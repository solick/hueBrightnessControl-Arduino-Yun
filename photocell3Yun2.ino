/* This code was inspired by the example code of adafruit.com */
/**
Copyright (C) 2015 Lyn Matten
Open Source: Apache Licence 2.0
All Rights reserved
**/

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include "config.h"

 


void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  pinMode(lowPin, OUTPUT);
  pinMode(mediumPin, OUTPUT);
  pinMode(highPin, OUTPUT);
  pinMode(button, INPUT);
  
  digitalWrite(LEDpin, LOW); 
  
  Bridge.begin();
  
  for(count = 0; count < 3; count++) {
    
    Serial.println(count);
   
   digitalWrite(lowPin, HIGH);
   digitalWrite(mediumPin, HIGH);
   digitalWrite(highPin, HIGH);
   
   delay(100);
   
   digitalWrite(lowPin, LOW);
   digitalWrite(mediumPin, LOW);
   digitalWrite(highPin, LOW);
   
   delay(100);
   
   server.listenOnLocalhost();
   server.begin();
    
  }

   
}
 
void loop(void) {
  
  int oldValue = rawValue;
   
   rawValue = analogRead(photocellPin);  

   checkStateForPhotoCell(oldValue, rawValue);
  
  YunClient client = server.accept();
  
  if(client) {
    process(client);
    client.stop();
  }
  
  checkButtonState();
 

  delay(100);
}




