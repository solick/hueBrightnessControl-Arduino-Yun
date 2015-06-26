

/***************/
void checkStateForPhotoCell(int oldV, int newV) {
/***************/

   if(active == 1)
  {
    
    int actualState = brightnessState;
    int newState = 0;
    
    if(checkJitter(oldV, newV) == 0) {
       return; 
    }
    
    //int tick = timer.checkTime();
    int performChange = 1;
/*    
    if(tick == -1) {
      
      timer.start();
      performChange = 1;
      
    }
    else {
      
      Serial.print("tick: ");
      Serial.println(tick);
      
      if(tick >= delayTime) {
         
         timer.stop();
        performChange = 1; 
        
      }
     
      
    }
    
    */
    
    
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
            
            brightnessState = newState;
          
          setLEDState();  
              
            
          }
          
      
      
    }
    
 

  
  
}


