#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include "arduino.h"

#define led 2


RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

uint32_t end_time = 0;
uint32_t end_time2 = 0;

const char text[] = "Tilkoblingstest";
int potpin=0;

void setup() {
  pinMode(led,OUTPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  
}
void loop() {
  /*
  if(digitalRead(led) && millis() > end_time){
    digitalWrite(led,LOW);
  }
  if(millis()>end_time2){
    //radio.write(&text, sizeof(text));

    
    
    digitalWrite(led,HIGH);
    end_time2 = millis()+9000;
    end_time = millis()+1000;
  }*/
  delay(5);
  int potValue=analogRead(0);
  int angleValue=map(potValue,0,1023,50,130);
  if (angleValue<80 or angleValue>100){
    digitalWrite(led,HIGH);
    radio.write(&angleValue,sizeof(angleValue));//
    end_time=millis()+100;
  }/*else{
    angleValue=89;
  }*/
    //radio.write(&angleValue,sizeof(angleValue));//PUTT DEN INN I FØRSTE IF-SETNING???
    
  if(digitalRead(led) && millis() > end_time){
    digitalWrite(led,LOW);
  }
  

  
  /*
  delay(5);//?
  int potValue=analogRead(A0);
  int angleValue=map(potValue,0,1023,20,160);
  radio.write(&angleValue,sizeof(angleValue));
  */
}
