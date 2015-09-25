
int checkJitter(int oldVal, int newVal) {
  
  Serial.print("oldVal: ");
  Serial.print(oldVal);
  Serial.print("  -- newVal: ");
  Serial.println(newVal);
  
 
  if(newVal >= lowLimit && newVal < highLimit) {
    /** check if too much medium **/
    //Serial.println("newVal >= lowLimit && newVal < highLimit");
    
    /** check to which limit newVal is closer **/
    int diff = highLimit - lowLimit;
    
    if((newVal - lowLimit) < (highLimit - newVal) ) {
      //closer to low Limit
      //Serial.println("closer to low");
      if((newVal - lowLimit) > jitter) {
      return 1; 
      }
    }
    else {
      if((highLimit- newVal) > jitter) {
        //Serial.println("closer to high");
      return 1; 
      }
      
    }
    
    
    
    
  }
  else if(newVal < lowLimit) {
    /* check if too much low */
    
    //Serial.println("newVal < lowLimit");
    if((lowLimit - newVal) > jitter) {
      return 1; 
    }
    
  }
  else if(newVal >= highLimit) {
    
    /** check if too much high **/
    //Serial.print("newVal - highLimit) > jitter: ");
    //Serial.println((newVal - highLimit) > jitter);
    if((newVal - highLimit) > jitter) {
      return 1; 
    }
    
  }
  
 
 return 0; 

  
}
