

/***************/
void process(YunClient client) {
/***************/

  
  String retStr = "N.N.";

  if (active == 0 ) {
    
    client.println("not active");
  }
  
  else {
      
    String command = client.readStringUntil('\r');
    Serial.println(command);
  
    if (command == "brightness") {
      
      if(brightnessState == lowBrightness) {
      
          retStr = "LOW";
        
      }
      else if(brightnessState == mediumBrightness) {
        
         retStr = "MEDIUM"; 
      }
      else if(brightnessState == highBrightness) {
         retStr = "HIGH"; 
        
      }
      
      client.println(retStr); 
    }
    else {
      
      client.println("wrong url");
    }
  }


 
}

