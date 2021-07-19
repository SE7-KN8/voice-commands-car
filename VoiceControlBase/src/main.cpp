#include <Arduino.h>
#include <Servo.h>

Servo servo;

void stop()
{
  analogWrite(3, LOW);
  analogWrite(9, LOW);
  analogWrite(10, LOW);
  analogWrite(11, LOW);
}

void go()
{
  stop();
  servo.write(90);
  analogWrite(3, 100);
  analogWrite(11, 100);
}

void backwards()
{
  stop();
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(3, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Serial.begin(9600);
  servo.attach(8);
}

void left()
{
  servo.write(60);
}

void right()
{
  servo.write(120);
}

void loop()
{
  if (Serial.available())
  {
    char c = Serial.read();

    switch (c)
    {
    case 'g':
    {
      go();
      break;
    }
    case 's':
    {
      stop();
      break;
    }
    case 'b':
    {
      backwards();
      break;
    }
    case 'r':
    {
      right();
      break;
    }
    case 'l':
    {
      left();
      break;
    }
    default:
      break;
    }
  }
}