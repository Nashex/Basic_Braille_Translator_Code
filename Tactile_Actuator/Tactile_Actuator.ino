int leftPin = 11; //This turns on the left actuator
int rightPin = 10;
int buttonPin = 13; 

int onT;
int offT;

int onPulse = 1500;
int offPulse = 100;

int spot = 0;

void setup() {
  pinMode(leftPin, OUTPUT);
  pinMode(rightPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  bool buttonState = LOW;
}

// the loop function runs over and over again forever
void loop() {
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    clearReg();
    if (spot <= 1) {
      spot = spot + 1;
    } else {
      spot = 0;
    }
  buttonState = LOW;
  Serial.println("Button was pressed");
  Serial.print(spot);
  clearReg();
  delay(1000);
  }
  dispLetter(spot, onPulse, offPulse);
}

void clearReg() {
  digitalWrite(leftPin, LOW);
  digitalWrite(rightPin, LOW);
}

void leftPinS(int on, int off) {
  digitalWrite(leftPin, HIGH);
  delay(on);
  clearReg();
  delay(off);
}

void rightPinS(int on, int off) {
  digitalWrite(rightPin, HIGH);
  delay(on);
  clearReg();
  delay(off);
}

void dispLetter(int spot, int on, int off) {
  if (spot == 0) {
    leftPinS(on, off);
  } else if (spot == 1) {
    rightPinS(on, off);
  } else {
    clearReg();
  }
}
