# Voice Controlled Car

(This is a submission to the 2021 TensorFlow Microcontroller Challenge)

## Overview
This project features a car which can controlled by voice commands such as "go", "left", "right" and "stop". To achive this two microcontrollers are used. One Arduino Uno for controlling the motors and one Arduino 33 Ble Sense for receiving the voice input and run the infercing using a trained tensorflow lite model. The final command is sent via a serial port to the arduino uno which parses the command and set the motors accordingly.

## Source code
The source code for the project is in two dictionaries. The first "Arduino33BleSenseTest" features the code for the Arduino 33 Ble Sense which contains the TFLite model and the sending data part. The second "VoiceControlBase" is the code for the Arduino Uno which contains the control code for the motors and the command parser.

## Schematic 

[Add image...]


## Model creating and training
The traing data for the voice commands was created using TensorFlow/Google Speech Commands Dataset. The base data was modified with some noise to allow the model to learn using the conditions on the microcontroller. To build and train a TFlite model, EdgeImpulse was used. At first all training data was uploaded to EdgeImpulse. Then for the model an MFCC filter was used because the project only feature human audio samples and so the model could be better trained in the application. Then the model was trained and exported as an Arduino library to which the code was added to control the car.


