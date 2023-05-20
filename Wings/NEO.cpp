#include "NEO.h"
#include "MotionProfile.h"
#include <Servo.h> 
#include <ArduPID.h>

MotionProfile trapezoidalProfile(3500, 1000, 1, 10, .7);
Servo servo; 
ArduPID PID;

NEO::NEO(int inPin) 
{
  pin = inPin;
  pos = 1500;
  targetPos = 0;
  servo.attach(inPin, 1000, 2000);
  servo.writeMicroseconds(pos);
  double p = .012;
  double i = 0.00001;
  double d = 0.0;
  PID.begin(&pos, &motorCommand, &smoothedTargetPos, p, i, d);
  PID.setOutputLimits(-1, 1);
  PID.start();
}
void NEO::setPosition(double pos)
{
  targetPos = pos;
}
void NEO::logic(int encoderPos)
{
//  Serial.print(motorCommand);
//  Serial.print("\t");
//  Serial.print(pos);
//  Serial.print("\t");
//  Serial.println(motorCommand);
  smoothedTargetPos = trapezoidalProfile.update(targetPos);
  Serial.print(targetPos);
  Serial.print("\t");
  Serial.print(smoothedTargetPos);
  Serial.print("\t");
  Serial.println(pos);
  
  pos = encoderPos;
  PID.compute();
  int micro = -motorCommand*500+1500;
  servo.writeMicroseconds(micro);
}
float NEO::getPosition()
{
  return pos;
}

float NEO::getTarget()
{
  return targetPos;
}
