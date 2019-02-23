//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

int nextButtonPin = 3;
int backButtonPin = 4;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

bool backButtonS = 0;
bool nextButtonS = 0;

byte regOne;
byte regTwo;
byte regThree;

byte screenDisplay[21];

bool row[3] = {0,0,0};
bool col[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
bool cell[7] = {0,0,0,0,0,0,0};

bool onScreen = 1;

String inString;
int str_len;

bool a[6] = {1,0,0,0,0,0};
bool b[6] = {1,0,1,0,0,0};
bool c[6] = {1,1,0,0,0,0};
bool d[6] = {1,1,0,1,0,0};
bool e[6] = {1,0,0,1,0,0};
bool f[6] = {1,1,1,0,0,0};
bool g[6] = {1,1,1,1,0,0};
bool h[6] = {1,0,1,1,0,0};
bool i[6] = {0,1,1,0,0,0};
bool j[6] = {0,1,1,1,0,0};
bool k[6] = {1,0,0,0,1,0};
bool l[6] = {1,0,1,0,1,0};
bool m[6] = {1,1,0,0,1,0};
bool n[6] = {1,1,0,1,1,0};
bool o[6] = {1,0,0,1,1,0};
bool p[6] = {1,1,1,0,1,0};
bool q[6] = {1,1,1,1,1,0};
bool r[6] = {1,0,1,1,1,0};
bool s[6] = {0,1,1,0,1,0};
bool t[6] = {0,1,1,1,1,0};
bool u[6] = {1,0,0,0,1,1};
bool v[6] = {1,0,1,0,1,1};
bool w[6] = {0,1,1,1,0,1};
bool x[6] = {1,1,0,0,1,1};
bool y[6] = {1,1,0,1,1,1};
bool z[6] = {1,0,0,1,1,1};
bool hash[6] = {0,1,0,1,1,1};
bool space[6] = {0,0,0,0,0,0};
bool upperCase[6] = {0,0,0,0,1,0};

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(nextButtonPin, INPUT);
  pinMode(backButtonPin, INPUT);
  Serial.begin(9600);
  clearReg();
}

//Code to turn my boolean arrays into bytes
byte boolArrayToByte(bool boolArray[8])
{
  byte result = 0; 

  for(int i = 0; i < 8; i++)
  {
    if(boolArray[i])
    {
      result = result | (1 << i);
    }
  }

  return result;
}

// the heart of the program
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}

//Code to clear the display
void clearReg() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, 0);
  shiftOut(dataPin, clockPin, 0);
  shiftOut(dataPin, clockPin, 0);
  digitalWrite(latchPin, HIGH);
}

//Code for top left braille dot
void topLeft(int cell, int on, int off) {
  //Clears bools  
  bool regOne[8] = {0,0,0,0,0,0,0,0}; 
  bool regTwo[8] = {0,0,0,0,0,0,0,0}; 
  
  //Sets latch LOW
  digitalWrite(latchPin, LOW);
  //Sends data for letterA out
  shiftOut(dataPin, clockPin, 12); //Turns Rows 2 and 3 off
    
    switch(cell) {
      case 1:
      regOne[1] = 1;
      break;
      
      case 2:
      regOne[3] = 1;
      break;
      
      case 3:
      regOne[5] = 1;
      break;

      case 4:
      regOne[7] = 1;
      break;

      case 5:
      regTwo[2] = 1;
      break;

      case 6:
      regTwo[4] = 1;
      break;

      case 7:
      regTwo[6] = 1;
      break;
      
    }
    
    byte byteOne = boolArrayToByte(regOne);
    byte byteTwo = boolArrayToByte(regTwo);
    shiftOut(dataPin, clockPin, byteTwo);
    shiftOut(dataPin, clockPin, byteOne);
    digitalWrite(latchPin, HIGH);
    delay(on);
    clearReg();
    delay(off);
}

//Code for top right braille dot
void topRight(int cell, int on, int off) {
  //Clears bools  
  bool regOne[8] = {0,0,0,0,0,0,0,0}; 
  bool regTwo[8] = {0,0,0,0,0,0,0,0}; 
  
  //Sets latch LOW
  digitalWrite(latchPin, LOW);
  //Sends data for letterA out
  shiftOut(dataPin, clockPin, 12); //Turns Rows 2 and 3 off
    
    switch(cell) {
      case 1:
      regOne[2] = 1;
      break;
      
      case 2:
      regOne[4] = 1;
      break;
      
      case 3:
      regOne[6] = 1;
      break;

      case 4:
      regTwo[1] = 1;
      break;

      case 5:
      regTwo[3] = 1;
      break;

      case 6:
      regTwo[5] = 1;
      break;

      case 7:
      regTwo[7] = 1;
      break;
      
    }
    
    byte byteOne = boolArrayToByte(regOne);
    byte byteTwo = boolArrayToByte(regTwo);
    shiftOut(dataPin, clockPin, byteTwo);
    shiftOut(dataPin, clockPin, byteOne);
    digitalWrite(latchPin, HIGH);
    delay(on);
    clearReg();
    delay(off);
}

//Code for middle left braille dot
void middleLeft(int cell, int on, int off) {
  //Clears bools  
  bool regOne[8] = {0,0,0,0,0,0,0,0}; 
  bool regTwo[8] = {0,0,0,0,0,0,0,0}; 
  
  //Sets latch LOW
  digitalWrite(latchPin, LOW);
  //Sends data for letterA out
  shiftOut(dataPin, clockPin, 10); //Turns Rows 2 and 3 off
    
    switch(cell) {
      case 1:
      regOne[1] = 1;
      break;
      
      case 2:
      regOne[3] = 1;
      break;
      
      case 3:
      regOne[5] = 1;
      break;

      case 4:
      regOne[7] = 1;
      break;

      case 5:
      regTwo[2] = 1;
      break;

      case 6:
      regTwo[4] = 1;
      break;

      case 7:
      regTwo[6] = 1;
      break;
      
    }
    
    byte byteOne = boolArrayToByte(regOne);
    byte byteTwo = boolArrayToByte(regTwo);
    shiftOut(dataPin, clockPin, byteTwo);
    shiftOut(dataPin, clockPin, byteOne);
    digitalWrite(latchPin, HIGH);
    delay(on);
    clearReg();
    delay(off);
}

//Code for middle right braille dot
void middleRight(int cell, int on, int off) {
  //Clears bools  
  bool regOne[8] = {0,0,0,0,0,0,0,0}; 
  bool regTwo[8] = {0,0,0,0,0,0,0,0}; 
  
  //Sets latch LOW
  digitalWrite(latchPin, LOW);
  //Sends data for letterA out
  shiftOut(dataPin, clockPin, 10); //Turns Rows 2 and 3 off
    
    switch(cell) {
      case 1:
      regOne[2] = 1;
      break;
      
      case 2:
      regOne[4] = 1;
      break;
      
      case 3:
      regOne[6] = 1;
      break;

      case 4:
      regTwo[1] = 1;
      break;

      case 5:
      regTwo[3] = 1;
      break;

      case 6:
      regTwo[5] = 1;
      break;

      case 7:
      regTwo[7] = 1;
      break;
      
    }
    
    byte byteOne = boolArrayToByte(regOne);
    byte byteTwo = boolArrayToByte(regTwo);
    shiftOut(dataPin, clockPin, byteTwo);
    shiftOut(dataPin, clockPin, byteOne);
    digitalWrite(latchPin, HIGH);
    delay(on);
    clearReg();
    delay(off);
}

//Code for bottom left braille dot
void bottomLeft(int cell, int on, int off) {
  //Clears bools  
  bool regOne[8] = {0,0,0,0,0,0,0,0}; 
  bool regTwo[8] = {0,0,0,0,0,0,0,0}; 
  
  //Sets latch LOW
  digitalWrite(latchPin, LOW);
  //Sends data for letterA out
  shiftOut(dataPin, clockPin, 6); //Turns Rows 2 and 3 off
    
    switch(cell) {
      case 1:
      regOne[1] = 1;
      break;
      
      case 2:
      regOne[3] = 1;
      break;
      
      case 3:
      regOne[5] = 1;
      break;

      case 4:
      regOne[7] = 1;
      break;

      case 5:
      regTwo[2] = 1;
      break;

      case 6:
      regTwo[4] = 1;
      break;

      case 7:
      regTwo[6] = 1;
      break;
      
    }
    
    byte byteOne = boolArrayToByte(regOne);
    byte byteTwo = boolArrayToByte(regTwo);
    shiftOut(dataPin, clockPin, byteTwo);
    shiftOut(dataPin, clockPin, byteOne);
    digitalWrite(latchPin, HIGH);
    delay(on);
    clearReg();
    delay(off);
}

//Code for bottom right braille dot
void bottomRight(int cell, int on, int off) {
  //Clears bools  
  bool regOne[8] = {0,0,0,0,0,0,0,0}; 
  bool regTwo[8] = {0,0,0,0,0,0,0,0}; 
  
  //Sets latch LOW
  digitalWrite(latchPin, LOW);
  //Sends data for letterA out
  shiftOut(dataPin, clockPin, 6); //Turns Rows 2 and 3 off
    
    switch(cell) {
      case 1:
      regOne[2] = 1;
      break;
      
      case 2:
      regOne[4] = 1;
      break;
      
      case 3:
      regOne[6] = 1;
      break;

      case 4:
      regTwo[1] = 1;
      break;

      case 5:
      regTwo[3] = 1;
      break;

      case 6:
      regTwo[5] = 1;
      break;

      case 7:
      regTwo[7] = 1;
      break;
      
    }
    
    byte byteOne = boolArrayToByte(regOne);
    byte byteTwo = boolArrayToByte(regTwo);
    shiftOut(dataPin, clockPin, byteTwo);
    shiftOut(dataPin, clockPin, byteOne);
    digitalWrite(latchPin, HIGH);
    delay(on);
    clearReg();
    delay(off);
}

void dispLetter(bool let[],int cell, int on, int off) {
  if (let[0] == 1) {
    topLeft(cell, on, off);
  }
  if (let[1] == 1) {
    topRight(cell, on, off);
  }
  if (let[2] == 1) {
    middleLeft(cell, on, off);
  }
  if (let[3] == 1) {
    middleRight(cell, on, off);
  }
  if (let[4] == 1) {
    bottomLeft(cell, on, off);
  }
  if (let[5] == 1) {
    bottomRight(cell, on, off);
  }
}

void loop() {
  int dotsOn = 0;
  int on;
  int off;
  Serial.println ("What word would you like to display?");         //Prints the line "What word would you like to display?" in the Serial console
  while (Serial.available() == 0) { }           //Waits until the user inputs a word or character
  inString = Serial.readString();           //Once a word in taken in as an input, it stores the input in the variable/string named "inString"
  str_len = inString.length() + 1;          //This calculates the length of the word and takes into account the null, hence the "+ 1"
  char charArray[str_len];          //This creates the character array called "charArray" and makes it the length of the word/message, hence the str_len integer located in the square brackets
  inString.toLowerCase();
  inString.toCharArray(charArray, str_len); 

  int spot = 0;
  int spotS = 0;
  
    while (Serial.available() == 0) { 
      
    for (spot = 0 + spotS; spot < spotS + 7; spot++) {
      if (charArray[spot] == 'a') {
      dotsOn = dotsOn + 1;
      } else if (charArray[spot] == 'b') {
        dotsOn = dotsOn + 2;
      } else if (charArray[spot] == 'c') {
        dotsOn = dotsOn + 2;
      } else if (charArray[spot] == 'd') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'e') {
        dotsOn = dotsOn + 2;
      } else if (charArray[spot] == 'f') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'g') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 'h') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'i') {
        dotsOn = dotsOn + 2;
      } else if (charArray[spot] == 'j') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'k') {
        dotsOn = dotsOn + 2;
      } else if (charArray[spot] == 'l') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'm') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'n') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 'o') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'p') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 'q') {
        dotsOn = dotsOn + 5;
      } else if (charArray[spot] == 'r') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 's') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 't') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 'u') {
        dotsOn = dotsOn + 3;
      } else if (charArray[spot] == 'v') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 'w') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 'x') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == 'y') {
        dotsOn = dotsOn + 5;
      } else if (charArray[spot] == 'z') {
        dotsOn = dotsOn + 4;
      } else if (charArray[spot] == ' ') {
        dotsOn = dotsOn + 0;
      }

  }

    on = 1;
    off =0;
    
        // read the state of the pushbutton value:
/*  nextButtonS = digitalRead(nextButtonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if ( nextButtonS == HIGH) {
    spotS = spotS + 1;
    delay(10);
  } 
  
  backButtonS = digitalRead(backButtonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (backButtonS == HIGH) {
    spotS = spotS - 1;
    delay(10);
  } */
  
    spot = 0;
    nextButtonS = digitalRead(nextButtonPin);
    backButtonS = digitalRead(backButtonPin);
    
    for (spot = 0 + spotS ; spot < spotS + 7; spot++) {
    
      start:
      
      if (charArray[spot] == 'a') {
      dispLetter(a, spot + 1, on, off);
      } else if (charArray[spot] == 'b') {
        dispLetter(b, spot + 1, on, off);
      } else if (charArray[spot] == 'c') {
        dispLetter(c, spot + 1, on, off);
        dotsOn = dotsOn + 1;
      } else if (charArray[spot] == 'd') {
        dispLetter(d, spot + 1, on, off);
      } else if (charArray[spot] == 'e') {
        dispLetter(e, spot + 1, on, off);
      } else if (charArray[spot] == 'f') {
        dispLetter(f, spot + 1, on, off);
      } else if (charArray[spot] == 'g') {
        dispLetter(g, spot + 1, on, off);
      } else if (charArray[spot] == 'h') {
        dispLetter(h, spot + 1, on, off);
      } else if (charArray[spot] == 'i') {
        dispLetter(i, spot + 1, on, off);
      } else if (charArray[spot] == 'j') {
        dispLetter(j, spot + 1, on, off);
      } else if (charArray[spot] == 'k') {
        dispLetter(k, spot + 1, on, off);
      } else if (charArray[spot] == 'l') {
        dispLetter(l, spot + 1, on, off);
      } else if (charArray[spot] == 'm') {
        dispLetter(m, spot + 1, on, off);
      } else if (charArray[spot] == 'n') {
        dispLetter(n, spot + 1, on, off);
      } else if (charArray[spot] == 'o') {
        dispLetter(o, spot + 1, on, off);
      } else if (charArray[spot] == 'p') {
        dispLetter(p, spot + 1, on, off);
      } else if (charArray[spot] == 'q') {
        dispLetter(q, spot + 1, on, off);
      } else if (charArray[spot] == 'r') {
        dispLetter(r, spot + 1, on, off);
      } else if (charArray[spot] == 's') {
        dispLetter(s, spot + 1, on, off);
      } else if (charArray[spot] == 't') {
        dispLetter(t, spot + 1, on, off);
      } else if (charArray[spot] == 'u') {
        dispLetter(u, spot + 1, on, off);
      } else if (charArray[spot] == 'v') {
        dispLetter(v, spot + 1, on, off);
      } else if (charArray[spot] == 'w') {
        dispLetter(w, spot + 1, on, off);
      } else if (charArray[spot] == 'x') {
        dispLetter(x, spot + 1, on, off);
      } else if (charArray[spot] == 'y') {
        dispLetter(y, spot + 1, on, off);
      } else if (charArray[spot] == 'z') {
        dispLetter(z, spot + 1, on, off);
      } else if (charArray[spot] == ' ') {
        dispLetter(space, spot + 1, on, off);
      }
/*      
      else if (isdigit(charArray[spot])) {
        if (isdigit(charArray[spot-1])) {
          
        if (charArray[spot] == '1') {
        dispLetter(a, spot + 1, on, off);
        } else if (charArray[spot] == '2') {
          dispLetter(b, spot + 1, on, off);
        } else if (charArray[spot] == '3') {
          dispLetter(c, spot + 1, on, off);
        } else if (charArray[spot] == '4') {
          dispLetter(d, spot + 1, on, off);
        } else if (charArray[spot] == '5') {
          dispLetter(e, spot + 1, on, off);
        } else if (charArray[spot] == '6') {
          dispLetter(f, spot + 1, on, off);
        } else if (charArray[spot] == '7') {
          dispLetter(g, spot + 1, on, off);
        } else if (charArray[spot] == '8') {
          dispLetter(h, spot + 1, on, off);
        } else if (charArray[spot] == '9') {
          dispLetter(i, spot + 1, on, off);
        } else if (charArray[spot] == '0') {
          dispLetter(j, spot + 1, on, off);
        }
        
        } else {
        dispLetter( hash , spot + 1, on, off);
        spot = spot + 1;
        if (charArray[spot-1] == '1') {
        dispLetter(a, spot + 1, on, off);
        } else if (charArray[spot-1] == '2') {
          dispLetter(b, spot + 1, on, off);
        } else if (charArray[spot-1] == '3') {
          dispLetter(c, spot + 1, on, off);
        } else if (charArray[spot-1] == '4') {
          dispLetter(d, spot + 1, on, off);
        } else if (charArray[spot-1] == '5') {
          dispLetter(e, spot + 1, on, off);
        } else if (charArray[spot-1] == '6') {
          dispLetter(f, spot + 1, on, off);
        } else if (charArray[spot-1] == '7') {
          dispLetter(g, spot + 1, on, off);
        } else if (charArray[spot-1] == '8') {
          dispLetter(h, spot + 1, on, off);
        } else if (charArray[spot-1] == '9') {
          dispLetter(i, spot + 1, on, off);
        } else if (charArray[spot-1] == '0') {
          dispLetter(j, spot + 1, on, off);
        }
*/        
        }
      }
    }
