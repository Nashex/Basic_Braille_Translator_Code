int bottomLeft = 2;         //Makes it so that you can set the location of the DIGITAL I/O pin for each character
int bottomRight = 3;         //Makes it so that you can set the location of the DIGITAL I/O pin for each character
int middleLeft = 4;         //Makes it so that you can set the location of the DIGITAL I/O pin for each character
int middleRight = 5;         //Makes it so that you can set the location of the DIGITAL I/O pin for each character
int topLeft = 6;         //Makes it so that you can set the location of the DIGITAL I/O pin for each character
int topRight = 7;         //Makes it so that you can set the location of the DIGITAL I/O pin for each character

String inString;      //String variable to store the input
int str_len;           //String length
int waitTime = 1000;         //This sets the waitTime which is currently 1000 milliseconds or 1 second

void setup() {
  Serial.begin(9600);         //This starts the Serial console at a rate of 9topLeft00 baud
  pinMode(bottomLeft, OUTPUT);         //This sets the pins bottomLeft to output 
  pinMode(bottomRight, OUTPUT);         //This sets the pins bottomRight to output 
  pinMode(middleLeft, OUTPUT);         //This sets the pins middleLeft to output 
  pinMode(middleRight, OUTPUT);         //This sets the pins middleRight to output 
  pinMode(topLeft, OUTPUT);         //This sets the pins topLeft to output 
  pinMode(topRight, OUTPUT);         //This sets the pins topRight to output 
}

void loop() {
  Serial.println ("What word would you like to display?");         //Prints the line "What word would you like to display?" in the Serial console
  while (Serial.available() == 0) { }           //Waits until the user inputs a word or character
  inString = Serial.readString();           //Once a word in taken in as an input, it stores the input in the variable/string named "inString"
  str_len = inString.length() + 1;          //This calculates the length of the word and takes into account the null, hence the "+ 1"
  char charArray[str_len];          //This creates the character array called "charArray" and makes it the length of the word/message, hence the str_len integer located in the square brackets
  inString.toCharArray(charArray, str_len);         //This converts the string "inString" to a character array named "charArray" which is the size of the word/message

  for (int i = 0; i<= str_len; i++) {         //This is a for loop that runs for the length of the word/message
  start:

      digitalWrite(bottomLeft, LOW);         //This turns pins bottomLeft off  
      digitalWrite(bottomRight, LOW);         //This turns pins bottomRight off 
      digitalWrite(middleLeft, LOW);         //This turns pins middleLeft off 
      digitalWrite(middleRight, LOW);         //This turns pins middleRight off 
      digitalWrite(topLeft, LOW);         //This turns pins topLeft off 
      digitalWrite(topRight, LOW);         //This turns pins topRight off 

    if (charArray[i] == 'a') {          //This is the if statement for the character 'a'
      Serial.println("a");        //This prints the character 'a' back into the Serial console
      digitalWrite(topLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'b') {          //This is the if statement for the character 'b'
      Serial.println("b");        //This prints the character 'b' back into the Serial console
      digitalWrite(topLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'c') {          //This is the if statement for the character 'c'
      Serial.println("c");        //This prints the character 'c' back into the Serial console
      digitalWrite(topLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'd') {          //This is the if statement for the character 'd'
      Serial.println("d");        //This prints the character 'd' back into the Serial console
      digitalWrite(middleRight, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }  

    if (charArray[i] == 'e') {          //This is the if statement for the character 'e'
      Serial.println("e");        //This prints the character 'e' back into the Serial console
      digitalWrite(middleRight, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }       

    if (charArray[i] == 'f') {          //This is the if statement for the character 'f'
      Serial.println("f");        //This prints the character 'f' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'g') {          //This is the if statement for the character 'g'
      Serial.println("g");        //This prints the character 'g' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    } 

    if (charArray[i] == 'h') {          //This is the if statement for the character 'h'
      Serial.println("h");        //This prints the character 'h' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }     

    if (charArray[i] == 'i') {          //This is the if statement for the character 'i'
      Serial.println("i");        //This prints the character 'i' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    } 

    if (charArray[i] == 'j') {          //This is the if statement for the character 'j'
      Serial.println("j");        //This prints the character 'j' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }     

    if (charArray[i] == 'k') {          //This is the if statement for the character 'k'
      Serial.println("k");        //This prints the character 'k' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    } 

    if (charArray[i] == 'l') {          //This is the if statement for the character 'l'
      Serial.println("l");        //This prints the character 'l' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    } 

    if (charArray[i] == 'm') {          //This is the if statement for the character 'm'
      Serial.println("m");        //This prints the character 'm' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'n') {          //This is the if statement for the character 'n'
      Serial.println("n");        //This prints the character 'n' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }      

    if (charArray[i] == 'o') {          //This is the if statement for the character 'o'
      Serial.println("o");        //This prints the character 'o' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'p') {          //This is the if statement for the character 'p'
      Serial.println("p");        //This prints the character 'p' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }    

    if (charArray[i] == 'q') {          //This is the if statement for the character 'q'
      Serial.println("q");        //This prints the character 'q' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'r') {          //This is the if statement for the character 'r'
      Serial.println("r");        //This prints the character 'r' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }    

    if (charArray[i] == 's') {          //This is the if statement for the character 's'
      Serial.println("s");        //This prints the character 's' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 't') {          //This is the if statement for the character 't'
      Serial.println("t");        //This prints the character 't' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(middleRight, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'u') {          //This is the if statement for the character 'u'
      Serial.println("u");        //This prints the character 'u' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }    

    if (charArray[i] == 'v') {          //This is the if statement for the character 'v'
      Serial.println("v");        //This prints the character 'v' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      digitalWrite(middleLeft, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'w') {          //This is the if statement for the character 'w'
      Serial.println("w");        //This prints the character 'w' back into the Serial console
      digitalWrite(bottomRight, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(middleRight, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }    

    if (charArray[i] == 'x') {          //This is the if statement for the character 'x'
      Serial.println("x");        //This prints the character 'x' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'y') {          //This is the if statement for the character 'y'
      Serial.println("y");        //This prints the character 'y' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 'z') {          //This is the if statement for the character 'z'
      Serial.println("z");        //This prints the character 'z' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '.') {          //This is the if statement for the character '.'
      Serial.println(".");        //This prints the character '.' back into the Serial console
      digitalWrite(bottomRight, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(middleRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == ',') {          //This is the if statement for the character ','
      Serial.println(",");        //This prints the character ',' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '?') {          //This is the if statement for the character '?'
      Serial.println("?");        //This prints the character '?' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      digitalWrite(middleLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '!') {          //This is the if statement for the character '!'
      Serial.println("!");        //This prints the character '!' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      digitalWrite(middleRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == 39) {          //This is the if statement for the character '''
      Serial.println("'");        //This prints the character ''' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '-') {          //This is the if statement for the character '-'
      Serial.println("-");        //This prints the character '-' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '#') {          //This is the if statement for the character '#'
      Serial.println("#");        //This prints the character '#' back into the Serial console
      digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, HIGH);
      digitalWrite(middleRight, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '0') {          //This is the if statement for the character '0'
      
        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }
        
      Serial.println("0");        //This prints the character '0' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '1') {          //This is the if statement for the character '1'
      
        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("1");        //This prints the character '1' back into the Serial console
      digitalWrite(topLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '2') {          //This is the if statement for the character '2'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) {           //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("2");        //This prints the character '2' back into the Serial console
      digitalWrite(topLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '3') {          //This is the if statement for the character '3'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("3");        //This prints the character '3' back into the Serial console
      digitalWrite(topLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '4') {          //This is the if statement for the character '4'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("4");        //This prints the character '4' back into the Serial console      
      digitalWrite(middleRight, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }  

    if (charArray[i] == '5') {          //This is the if statement for the character '5'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("5");        //This prints the character '5' back into the Serial console
      digitalWrite(middleRight, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }       

    if (charArray[i] == '6') {          //This is the if statement for the character '6'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("6");        //This prints the character '6' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] == '7') {          //This is the if statement for the character '7'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("7");        //This prints the character '7' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    } 

    if (charArray[i] == '8') {          //This is the if statement for the character '8'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("8");        //This prints the character '8' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(middleRight, HIGH);
      digitalWrite(topLeft, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }     

    if (charArray[i] == '9') {          //This is the if statement for the character '8'

        if (charArray[i-1] > 57 || charArray[i-1] < 48) { //This initiates if the previous character was not a number
          Serial.println("#");        //This prints the character '#' back into the Serial console
          digitalWrite(bottomLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
          digitalWrite(bottomRight, HIGH);
          digitalWrite(middleRight, HIGH);
          digitalWrite(topRight, HIGH);
          delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
        }

      Serial.println("9");        //This prints the character '8' back into the Serial console
      digitalWrite(middleLeft, HIGH);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(topRight, HIGH);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    } 


    if (charArray[i] == ' ') {          //This is the if statement for the character 'SPACE'
      Serial.println("SPACE");        //This prints the character 'SPACE' back into the Serial console
      digitalWrite(bottomLeft, LOW);          //These line/lines of code activate(s) the correct LED/PIN for the letter in Braille
      digitalWrite(bottomRight, LOW);
      digitalWrite(middleLeft, LOW);
      digitalWrite(middleRight, LOW);
      digitalWrite(topLeft, LOW);
      digitalWrite(topRight, LOW);
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
    }

    if (charArray[i] >= 65 && charArray[i] <= 90) {         //If a character is capital it converts it initiates the loop
      Serial.println("CAPITAL");        //This prints the character 'CAPITAL' back into the Serial console
      digitalWrite(bottomRight, HIGH);          //This activates the LED/pin to signal a capital letter 
      delay(waitTime);          //This gives the waitTime in seconds for the Braille to have sufficient time to be read
      charArray[i] = charArray[i] + 32;         //This converts the capital letter to a lowercase letter and reruns the loop
      goto start;         //This goes back to the start of the for loop
    }
    
    if (i == str_len) {          //After the word/message is complete this statement runs because the for loop stops when the int "i" is equal to the length of the message
      digitalWrite(bottomLeft, LOW);         //This turns pins bottomLeft off  
      digitalWrite(bottomRight, LOW);         //This turns pins bottomRight off 
      digitalWrite(middleLeft, LOW);         //This turns pins middleLeft off 
      digitalWrite(middleRight, LOW);         //This turns pins middleRight off 
      digitalWrite(topLeft, LOW);         //This turns pins topLeft off 
      digitalWrite(topRight, LOW);         //This turns pins topRight off                                
    }
  }
}
