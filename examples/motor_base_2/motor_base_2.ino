#include "WEMOS_Motor.h"

float pwm;

//Motor shiled I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
Motor M1(0x30,_MOTOR_A, 1000);//Motor A



void setup() {
  Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.printf("\r\nTest PWM 30 to 100, step 0.1,CW\r\n");
  for (pwm = 30; pwm <= 100; pwm+=0.1)
  {
    M1.setmotor( _CW, pwm);
   Serial.println(pwm);
    
  }
  
  M1.setmotor(_STOP);

  Serial.println("Motor A STOP");
  delay(200);
  
  Serial.printf("Test PWM 30 to 100, step 0.1,CCW\r\n");
  for (pwm = 30; pwm <= 100; pwm+=0.1)
  {
    M1.setmotor(_CCW, pwm);
    Serial.println(pwm);
  }
  
  M1.setmotor(_STOP);

  Serial.println("Motor A STOP");
  delay(200);

  
}
