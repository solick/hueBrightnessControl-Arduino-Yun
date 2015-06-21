
/***************/
void checkButtonState() {
/***************/ 
   

  // read button state
  buttonState = digitalRead(button);
  
  if(buttonState == HIGH) {
    
    Serial.println("ON");
    if(active == 0) {
      active = 1;
    }
    else {
      Serial.println("OFF");
      active = 0;
      
      //switch all leds off
       digitalWrite(lowPin, LOW);
       digitalWrite(mediumPin, LOW);
       digitalWrite(highPin, LOW);
      
    }
    //delay 1 s to give enough time to release the button
    delay(1000);
    
  }
  else {
    //Serial.println("OFF");
  }
   
  
}
