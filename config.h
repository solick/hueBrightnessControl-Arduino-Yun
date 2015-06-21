
/** Variables **/

int photocellPin = 0;     // the cell and 10K pulldown are connected to a0

int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int mediumPin = 12;
int lowPin = 9;
int highPin = 10;
       // 
int rawValue = 0; //raw analog value
int brightnessState = 0;

int button = 8;
int buttonState = 0;

int active = 0;

int count = 0;

int lowLimit = 750;
int highLimit = 900;

int delayTime = 20;

YunServer server;
lmTimer2 timer;

/** Structs **/

typedef enum  {
  
  lowBrightness = 1,
  mediumBrightness,
  highBrightness
  
} EnumBrightnessState;

EnumBrightnessState BRState;


