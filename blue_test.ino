#include <SoftwareSerial.h>
#define rxPin 10
#define txPin 11
#define forwardPin 4
#define backwardPin 5
#define leftPin 6
#define nwPin 7


SoftwareSerial BtSerial(rxPin,txPin);
char BT_ip;

void setup() {
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  pinMode(leftPin, OUTPUT);
  pinMode(nwPin, OUTPUT);
  BtSerial.begin(38400);
  Serial.write("setup done\n");
}

void loop() {
  if (BtSerial.available()){
    BT_ip = BtSerial.read();
    switch(BT_ip){
      case 'w':
      digitalWrite(forwardPin, HIGH);
      digitalWrite(backwardPin, LOW);
      digitalWrite(leftPin, LOW);
      digitalWrite(nwPin, LOW);
      break;

      case 's':
      digitalWrite(forwardPin, LOW);
      digitalWrite(backwardPin, HIGH);
      digitalWrite(leftPin, LOW);
      digitalWrite(nwPin, LOW);
      break;

      case 'a':      
      digitalWrite(forwardPin, LOW);
      digitalWrite(backwardPin, LOW);
      digitalWrite(leftPin, LOW);
      digitalWrite(nwPin, HIGH);
      break; 

      case 'd':
      digitalWrite(forwardPin, LOW);
      digitalWrite(backwardPin, LOW);
      digitalWrite(leftPin, HIGH);
      digitalWrite(nwPin, LOW);
      break;
    }
    Serial.write(BT_ip);
  }
  else{
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
    digitalWrite(leftPin, LOW);
    digitalWrite(nwPin, LOW);
    Serial.write("BtSerial not available\n");
  }
}
