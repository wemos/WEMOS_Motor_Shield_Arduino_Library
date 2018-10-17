#include <Wire.h>


#include "WEMOS_Motor.h"



//Motor shield default I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
Motor M1(0x30, _MOTOR_A, 1000); //Motor A
Motor M2(0x30, _MOTOR_B, 1000); //Motor B


void setup() {
  
  
  Serial.begin(57600);
  Serial.println("Starting demo");

  
}

void loop() {

  int pwm;

  Serial.println("for (pwm = 0; pwm <= 100; pwm++) { M1.setmotor( _CW, pwm); M2.setmotor(_CW, 100-pwm); }");
  for (pwm = 0; pwm <= 100; pwm++)
  {
    M1.setmotor( _CW, pwm);
    M2.setmotor(_CW, 100 - pwm);
    delay(100);
  }

  Serial.println("Motor STOP");
  M1.setmotor(_STOP);
  M2.setmotor( _STOP);

  delay(1000);

  Serial.println("for (pwm = 0; pwm <= 100; pwm++) { M1.setmotor(_CCW, pwm); M2.setmotor(_CCW, 100-pwm); }");
  for (pwm = 0; pwm <= 100; pwm++)
  {
    M1.setmotor(_CCW, pwm);
    M2.setmotor(_CCW, 100 - pwm);
    delay(100);

  }

  Serial.println("Motor STOP");
  M1.setmotor(_STOP);
  M2.setmotor( _STOP);
  delay(1000);


  Serial.println("Motor A&B SHORT BRAKE");
  M1.setmotor(_SHORT_BRAKE);
  M2.setmotor( _SHORT_BRAKE);
  delay(1000);

  Serial.println("Motor A&B STANDBY");
  M1.setmotor(_STANDBY);
  M2.setmotor( _STANDBY);
  delay(1000);

}
