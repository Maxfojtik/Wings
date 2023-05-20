#include "NEO.h"
#include <Encoder.h>
/**
 * Initialization
 *
 * @param int aVelocityMax maximum velocity (units/s)
 * @param int aAccelerationMax maximum acceleration (units/s^2)
 * @param short aMethod method of profile generation (1 = trapezoidal)
 * @param int aSampleTime sample time (ms)
 */

NEO leftNEO(4);
Encoder leftEncoder(2,3);

void setup() {
  Serial.begin(115200);
  delay(1000);
//  Serial.println("ready");
//  delay(1000);
//  Serial.println("go");
}

int signum(double x)
{
  return (x > 0) - (x < 0);
}
int loops = 0;
void loop() {
  leftNEO.logic(leftEncoder.read());
  if(loops%600==0)
  {
    leftNEO.setPosition(800);
  }
  if(loops%600==300)
  {
    leftNEO.setPosition(000);
  }
  loops++;
//  Serial.print(n1.getTarget());
//  Serial.print("\t");
//  Serial.println(leftEncoder.read());
  delay(10);
}
