# hueBrightnessControl-Arduino-Yun
A brightness detection and control for philips hue with Arduino Yun - atmel controller part

This has to be installed on a Arduino Yun and used together with hueBrightnessControlYun, a nodejs program wich has to be run on the OpenWRT side of Arduino Yun.

For maintenance reasions, the complete code has been separated into several files. Each file consits of a function.

## photocell3Yun2.ino

The main file and basic program loop

## config.h

All global and inital definitions and variables are declared here.

## checkButtonState.ino

Checks the stste of the button (pressed or not pressed) and calls the setLEDState function as well as sets the active flag to 1

## setLEDState.ino

Disables all LEDs and activate the LED according to the current brightness state

## checkStateForPhotoCell.ino

parameters oldValue and newValue

if active flag is yes, checks the jitter (checkJitter) to avoid switching to fast between different brightness states and than sets the currenct brightnessStatt.

## checkJitter.ino


## processYunServer.ioo



