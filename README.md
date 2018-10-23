# Wemos_D1_Motor_Shield
Arduino library for the Wemos D1 mini Motor Shield (i2c interface, TB6612 based).

## Firmware Warning

WARNING: The shipped firmware with the Motor Shield is bugged. You need to update it. You can update it from Windows with a D1 Mini.

## Update the firmware (from Windows)

### Step 1 

Upload an empty sketch to you D1 Mini. This will allow serial data to pass from the USB port to the Motor Shield. Basically, we are telling the D1 Mini to ignore all serial data that will pass through to the Motor Shield.

Sketch:
```
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

### Step 2

Solder RTS and 3V on the Motor Shield. This activates the reprogramming mode of the Motor Shield. Then build this circuit:
![Image of circuit to update the firmware](https://octodex.github.com/images/yaktocat.png)

### Step 3

Download STM32Flash from here https://sourceforge.net/projects/stm32flash/files/

Extract in a directory.

### Step 4

Download the motor_shield.bin: https://cdn.hackaday.io/files/18439788894176/motor_shield.bin

Extract and put in the same directory as ```stm32flash.exe``` downloaded in the step above.

### Step 4

Execute the following commands. IMPORTANT: Replace COM8 with the port of your Wemos D1 Mini.


```stm32flash.exe COM8``` Replace COM8 with the port of your Wemos D1 Mini.

![image of stm32flash.exe result](https://octodex.github.com/images/yaktocat.png)

```stm32flash.exe -k COM8``` This will unlock your shield, replace COM8 with the port of your Wemos D1 Mini

![image of stm32flash.exe -k result](https://octodex.github.com/images/yaktocat.png)

```stm32flash.exe -f -v -w motor_shield.bin COM8``` This will flash the bin and re-lock the shield, replace COM8 with the port of your Wemos D1 Mini.

![image of stm32flash.exe -f -v -w motor_shield.bin result](https://octodex.github.com/images/yaktocat.png)

### Sources

* https://www.letscontrolit.com/wiki/index.php/WemosMotorshield
* https://github.com/pbugalski/wemos_motor_shield
* https://hackaday.io/project/18439-motor-shield-reprogramming
