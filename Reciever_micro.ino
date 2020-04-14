#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include "arduino.h"

#define ledRed 2
#define ledBlue 8
#define ledGreen 6
#define trans 7

RF24 radio(3, 5); // CE, CSN
const byte address[6] = "00001";

Servo myServo;

int angle=90;
int count=0;

uint32_t end_time = 0;
uint32_t end_time2 = 0;
uint32_t end_time3 = 0;
uint32_t end_time4 = 0;
uint32_t end_time5 = 0;
uint32_t end_time6 = 0;



void setup() {
  Serial.begin(9600);//?
  pinMode(ledRed,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(trans,OUTPUT);
  myServo.attach(9);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  digitalWrite(trans,LOW);
  digitalWrite(ledRed,LOW);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledGreen,LOW);
  
  
}
void loop() {
  if (radio.available()){
    
    int angleValue=89;
    radio.read(&angleValue,sizeof(angleValue));
    Serial.println(angleValue);

    end_time2=millis()+50;
    
    if(angleValue<80 && angleValue>20){
      digitalWrite(trans,HIGH);
      digitalWrite(ledRed,HIGH);
      Serial.println(angleValue);
      myServo.write(angleValue);
      end_time=millis()+100;
      digitalWrite(ledGreen,HIGH);
      end_time5=millis()+100;
      
      }else if(angleValue>100){
        digitalWrite(trans,HIGH);
        digitalWrite(ledRed,HIGH);
        Serial.println(angleValue);
        myServo.write(angleValue);
        end_time=millis()+100;
        digitalWrite(ledBlue,HIGH);
        end_time6=millis()+100;
      }


      
      if(angleValue<10){
        digitalWrite(trans,LOW);
        if (count==0){
          end_time4=millis()+50;
          
        }count++;
      }

      if(millis()>end_time4){
        if(count>20){//HER KAN DET ENDRES
          transDisconnected();
        }count=0;
      }

      

       //angleValue blir 0 når transmitter blir frakoblet.0 kan også forekomme ellers. Må sjekke om 0 forekommer med feks 50ms mellom seg..
     /* if(angleValue<10){
        digitalWrite(trans,LOW);
        if (millis()<end_time3){
           
              
           


       //0 har forekommet 2 ganger ila 50ms... TRANS ER MEST SANNSYNLIG FRAKOBLET
                  transDisconnected();
          
          
        }else{
          end_time3=millis()+5;
        }
        
     
      }
      */
    }
    

    
    if(digitalRead(trans) && millis()>end_time){//digitalRead(trans) og digitalRead(led)?? evt to if-statements?
      digitalWrite(ledRed,LOW);
      digitalWrite(trans,LOW);
    }
    if(digitalRead(ledGreen) && millis()>end_time5){
      digitalWrite(ledGreen,LOW);
    }
    if(digitalRead(ledBlue) && millis()>end_time6){
      digitalWrite(ledBlue,LOW);
    }


}

void transDisconnected(){
  digitalWrite(trans,LOW);
  delay(1000); 
  digitalWrite(ledRed,LOW);
  delay(1000);
  digitalWrite(ledRed,HIGH);
  delay(1000); 
  digitalWrite(ledRed,LOW);
  delay(1000);//VELG HVOR LENGE MELLOM HVER RESET
  //Reset reciever arduino
  //IF RESET TRIED MORE THAN 5 TIMES, ABORT...

}

