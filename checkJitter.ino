
int checkJitter(int oldVal, int newVal) {
  
  Serial.print("oldVal: ");
  Serial.print(oldVal);
  Serial.print("  -- newVal: ");
  Serial.println(newVal);
  
  
  if(oldVal > newVal) {
    /** decreasing brightness **/
    if ((oldVal - newVal) > jitter) {
      return 1;
    }
    
    
    
  }
  else if(oldVal < newVal) {
   /** increasing brightness **/ 
   if((newVal - oldVal) > jitter) {
     return 1;
   }
    
  }
 
  
  
 
 return 0; 
  
}
