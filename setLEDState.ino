void setLEDState() {
 
            
             // switch all LEDs off
             digitalWrite(lowPin, LOW);
             digitalWrite(mediumPin, LOW);
             digitalWrite(highPin, LOW);
            
            Serial.print("BrightnessState: ");
            Serial.println(brightnessState);
            
            if(brightnessState == lowBrightness)
            {
              //low light
              digitalWrite(lowPin, HIGH);
            } 
            else if(brightnessState == mediumBrightness)
            {
              // normal light
              digitalWrite(mediumPin, HIGH);
            } 
            else if(brightnessState == highBrightness)
            {
              // brigt light
              digitalWrite(highPin, HIGH);
            }  
               
  
}
