#ifndef NEO_H
#define NEO_H
#include <Arduino.h>
class NEO {
  
  private:
    int pin;
    double pos;
    double targetPos;
    double smoothedTargetPos;
    double targetMicros;
    double motorCommand;
  public:
    NEO(int inPin);
    void setPosition(double iPos);
    void setTargetPosition(double iPos);
    float getPosition();
    float getTarget();
    void logic(int encoderPos);
};
#endif
