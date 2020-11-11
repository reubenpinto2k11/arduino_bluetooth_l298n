#include<SoftwareSerial.h>
//motor 1 control pins
#define mtr1enPin 9
#define mtr1in1Pin 8
#define mtr1in2Pin 7

//motor 2 control pins
#define mtr2in1Pin 5
#define mtr2in2Pin 4
#define mtr2enPin 3

// bluetooth data transfer pins
#define rxPin 10
#define txPin 11

//Defining serail IO pins & reqd globals for bluetooth
SoftwareSerial BtSerial(rxPin,txPin);
char BT_ip;

void setup() {
  //begin default serial connection
  Serial.begin(9600);
  
  //setup of all pins
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(mtr1enPin, OUTPUT);
  pinMode(mtr1in1Pin, OUTPUT);
  pinMode(mtr1in2Pin, OUTPUT);
  pinMode(mtr2enPin, OUTPUT);
  pinMode(mtr2in1Pin, OUTPUT);
  pinMode(mtr2in2Pin, OUTPUT);

  //begin bluetooth serial connection
  BtSerial.begin(38400);
  Serial.println("setup done");
}

void loop() {
  if (BtSerial.available()){
    BT_ip = BtSerial.read();
    switch(BT_ip){
      case 'w':
      analogWrite(mtr1enPin, 255);
      analogWrite(mtr2enPin, 255);
      digitalWrite(mtr1in1Pin, HIGH);
      digitalWrite(mtr1in2Pin, LOW);
      digitalWrite(mtr2in1Pin, HIGH);
      digitalWrite(mtr2in2Pin, LOW);
      break;

      case 's':   
      analogWrite(mtr1enPin, 255);
      analogWrite(mtr2enPin, 255);
      digitalWrite(mtr1in1Pin, LOW);
      digitalWrite(mtr1in2Pin, HIGH);
      digitalWrite(mtr2in1Pin, LOW);
      digitalWrite(mtr2in2Pin, HIGH);
      break;

      case 'a':      
      analogWrite(mtr1enPin, 0);
      analogWrite(mtr2enPin, 255);
      digitalWrite(mtr1in1Pin, LOW);
      digitalWrite(mtr1in2Pin, LOW);
      digitalWrite(mtr2in1Pin, HIGH);
      digitalWrite(mtr2in2Pin, LOW);
      break; 

      case 'd':
      analogWrite(mtr1enPin, 255);
      analogWrite(mtr2enPin, 0);
      digitalWrite(mtr1in1Pin, HIGH);
      digitalWrite(mtr1in2Pin, LOW);
      digitalWrite(mtr2in1Pin, LOW);
      digitalWrite(mtr2in2Pin, LOW);
      break;
    }
    Serial.write(BT_ip);
  }
  else{
    analogWrite(mtr1enPin, 0);
    analogWrite(mtr2enPin, 0);
    digitalWrite(mtr1in1Pin, LOW);
    digitalWrite(mtr1in2Pin, LOW);
    digitalWrite(mtr2in1Pin, LOW);
    digitalWrite(mtr2in2Pin, LOW);
    Serial.write("BtSerial not available\n");
  }
}
