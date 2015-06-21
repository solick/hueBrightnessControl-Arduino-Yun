/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground 
Connect LED from pin 11 through a resistor to ground 
For more information see http://learn.adafruit.com/photocells */

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <lmTimer2.h>
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
   
   rawValue = analogRead(photocellPin);  
   
    
  Serial.print("Analog reading = ");
  Serial.println(rawValue); // the raw analog reading

   checkStateForPhotoCell(rawValue);
  
  YunClient client = server.accept();
  
  if(client) {
    process(client);
    client.stop();
  }
  
  checkButtonState();
 

  delay(100);
}




