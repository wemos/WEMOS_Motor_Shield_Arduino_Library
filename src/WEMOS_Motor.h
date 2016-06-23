
#ifndef __WEMOS_MOTOR_H
#define __WEMOS_MOTOR_H


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "Wire.h"

#define _MOTOR_A 0
#define _MOTOR_B 1

#define _SHORT_BRAKE 0
#define _CCW  1
#define _CW 	2
#define _STOP 3
#define _STANDBY 4


class Motor{
public:
	Motor(uint8_t address, uint8_t motor, uint32_t freq);
	Motor(uint8_t address, uint8_t motor, uint32_t freq, uint8_t STBY_IO);
	void setfreq(uint32_t freq);
	void setmotor(uint8_t dir, float pwm_val);
	void setmotor(uint8_t dir);

private:
	uint8_t _address;
	uint8_t _motor;
	bool _use_STBY_IO=false;
	uint8_t _STBY_IO;

};


#endif

