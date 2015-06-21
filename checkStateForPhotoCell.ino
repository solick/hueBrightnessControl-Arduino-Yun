

/***************/
void checkStateForPhotoCell(int value) {
/***************/

   if(active == 1)
  {
    
    int actualState = brightnessState;
    int newState = 0;
    
    int tick = timer.checkTime();
    int performChange = 0;
    
    if(tick == -1) {
      
      timer.start();
      performChange = 1;
      
    }
    else {
      
      //Serial.print("tick: ");
      //Serial.println(tick);
      
      if(tick >= delayTime) {
         
         timer.stop();
        performChange = 1; 
        
      }
      
      
    }
    
    
    if(performChange == 1) {
      
         if(rawValue < lowLimit)
            {
              //low light
              newState = lowBrightness;
          
            } 
            else if(rawValue >= lowLimit && rawValue < highLimit)
            {
              // normal light
               newState = mediumBrightness;
            } 
            else if(rawValue >= highLimit)
            {
              // brigt light
               newState = highBrightness;
            }  
            
            
            
             // switch all LEDs off
             digitalWrite(lowPin, LOW);
             digitalWrite(mediumPin, LOW);
             digitalWrite(highPin, LOW);
            
            
            if(rawValue < lowLimit)
            {
              //low light
              digitalWrite(lowPin, HIGH);
              brightnessState = lowBrightness;
              
          
            } 
            else if(rawValue >= lowLimit && rawValue < highLimit)
            {
              // normal light
              digitalWrite(mediumPin, HIGH);
               brightnessState = mediumBrightness;
              
            } 
            else if(rawValue >= highLimit)
            {
              // brigt light
              digitalWrite(highPin, HIGH);
               brightnessState = highBrightness;
            }  
              
            
          }
          
      
      
    }
    
 

  
  
}


