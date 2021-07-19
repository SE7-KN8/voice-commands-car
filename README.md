# Voice Controlled Car

(This is a submission to the 2021 TensorFlow Microcontroller Challenge)

## Images
![Left view of the car](https://raw.githubusercontent.com/SE7-KN8/voice-commands-car/main/.images/left.jpg)
![Top view of the car](https://raw.githubusercontent.com/SE7-KN8/voice-commands-car/main/.images/top.jpg)
![Right view of the car](https://raw.githubusercontent.com/SE7-KN8/voice-commands-car/main/.images/right.jpg)

## Overview
This project features a car which can controlled by voice commands such as "go", "left", "right" and "stop". To achive this two microcontrollers are used. One Arduino Uno for controlling the motors and one Arduino 33 Ble Sense for receiving the voice input and run the infercing using a trained tensorflow lite model. The final command is sent via a serial port to the arduino uno which parses the command and set the motors accordingly.

## Source code
The source code for the project is in two dictionaries. The first "Arduino33BleSenseTest" features the code for the Arduino 33 Ble Sense which contains the TFLite model and the sending data part. The second "VoiceControlBase" is the code for the Arduino Uno which contains the control code for the motors and the command parser.

## Schematic 

![A simple schematic of the project in an electrical sense](https://raw.githubusercontent.com/SE7-KN8/voice-commands-car/main/.images/overview.png)


## Model creating and training
The traing data for the voice commands was created using TensorFlow/Google Speech Commands Dataset. The base data was modified with some noise to allow the model to learn using the conditions on the microcontroller. To build and train a TFlite model, EdgeImpulse was used. At first all training data was uploaded to EdgeImpulse. Then for the model an MFCC filter was used because the project only feature human audio samples and so the model could be better trained in the application. Then the model was trained and exported as an Arduino library to which the code was added to control the car.

## Use Cases

This Project is just a little fun project with no real use case, but it shows what is possible using ML and Microcontrollers. For example something like this can be used in electrical vehicles like E-Scooters or E-Bikes since the hardware and energy costs are very low in comparison to the "smartness" which can be added to an object using this way.

## Future considerations 
_Since this is my first project which involes ML, I didn't had the time to make it perfect. This mean there is work for the future:_: The speech model needs better accuracy. Currently it can understand the commands but fails in some cases, especially when there is background noise. Also sometimes the model needs more than one attempt to understand a command correctly.
