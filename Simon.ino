#include <SoftwareSerial.h>
#include <ArduinoBlue.h>
#include "ArrayList.h"
#define redLed 13
#define greenLed 12
#define blueLed 8
#define yellowLed 7
#define buzzer 9
SoftwareSerial bt(2, 4);  // TX, RX
ArduinoBlue phone(bt); // pass reference of bluetooth object to ArduinoBlue constructor.
int button;
ArrayList <int> compSeq;
ArrayList <int> userSeq;
int randomLed;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
}

void loop() {
  randomLed = random(1, 5);
  compSeq.add(randomLed);
  for (int i = 0; i < compSeq.size(); i++){
    if (compSeq[i] == 1){
      tone(buzzer, 31);
      digitalWrite(redLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(redLed, LOW);
      delay(500);
    }
    else if (compSeq[i] == 2){
      tone(buzzer, 41);
      digitalWrite(greenLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(greenLed, LOW);
      delay(500);
    }
    else if (compSeq[i] == 3){
      tone(buzzer, 52);
      digitalWrite(blueLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(blueLed, LOW);
      delay(500);
    }
    else{
      tone(buzzer, 62);
      digitalWrite(yellowLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(yellowLed, LOW);
      delay(500);
    }
  }
  while(compSeq.size() != userSeq.size()){
    button = phone.getButton();
    if (button == 0){
      tone(buzzer, 31);
      digitalWrite(redLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(redLed, LOW);
      userSeq.add(button + 1);
    }
    if (button == 1){
      tone(buzzer, 41);
      digitalWrite(greenLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(greenLed, LOW);
      userSeq.add(button + 1);
    }
    if (button == 2){
      tone(buzzer, 52);
      digitalWrite(blueLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(blueLed, LOW);
      userSeq.add(button + 1);
    }
    if (button == 3){
      tone(buzzer, 62);
      digitalWrite(yellowLed, HIGH);
      delay(500);
      noTone(buzzer);
      digitalWrite(yellowLed, LOW);
      userSeq.add(button + 1);
    }

    for (int i = 0; i < userSeq.size(); i++){
      if (userSeq[i] != compSeq[i]){
        Serial.println("You Lose");
        userSeq.clear();
        compSeq.clear();
        break;
      }
    }
  }
  userSeq.clear();
  delay(1000);
}
