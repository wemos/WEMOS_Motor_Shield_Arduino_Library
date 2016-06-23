#include "WEMOS_Motor.h"

int pwm;
int standby_io = D3;

//Motor shiled I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
Motor M1(0x30, _MOTOR_A, 1000, standby_io); //Motor A



void setup() {
  Serial.begin(250000);
}

void loop() {

  for (pwm = 40; pwm <= 100; pwm++)
  {
    M1.setmotor( _CW, pwm);
    Serial.printf("A:%d%, B:%d%, DIR:CW\r\n", pwm, 100 - pwm);
    delay(500);
    M1.setmotor(_STANDBY);
    Serial.println("Motor A STANDBY");
    delay(100);
  }

  


}
