# 2ServoFlapSystem_on_-ChineseButterflyOrnithopter

Implementing 2ServoFlapSystem on Chinese butterfly ornithopter 

2ServoFlapSystem on Chinese butterfly ornithopter -RP2040 and ppmRX 

Created 2ServoFlapSystem for a Chinese Butterfly Ornithopter.  

Created code that allows for operation similar to the transmitter included with the Chinese Butterfly Ornithopter.

## Compatible boards:

RP2040-Tiny (requires a separate adapter for USB connection)
or RP2040-Zero (supports direct USB-C connection)

## Wiring

Wiring is the same as the RP2040-Tiny setup shown here:
https://github.com/KazuKaku/2ServoFlapOrnithopter

6V out to RX :6V in---> correct 5V out to RX :5V in

![Wiring](https://github.com/KazuKaku/2ServoFlapSystem_on_-ChineseButterflyOrnithopter/blob/532a624c456bb52c10deefc4670be8f92c66264a/image/260619%20RP2040-Tiny%20Wiring%20of%20%202ServoFlap%20System.jpg)


## Wing motion

Refer to the video below for operation. Note that the trim setting method differs.

260725 motion of Butterfly--china-- and My 2servoFlapOrnithopte Butterfly CODE

https://www.youtube.com/watch?v=8YyZEEd9J_o

## setting
Because the servo mounting configuration on the Chinese-made butterfly ornithopter differs from the standard setup, the servo connections are reversed.

Connect D5 (Right Servo) to the left servo on the ornithopter body.

Connect D6 (Left Servo) to the right servo on the ornithopter body.

## Setting of Transmitter 

Ch 1: Moving the stick to the right raises the right wing; the left wing remains stationary. Scale: 30–40%.

Ch 2: Moving the stick down lowers both wings. Scale: 30–40%.

Ch 3: Throttle; moving it up increases the flapping amplitude.

Ch 4: Difference in flapping amplitude between left and right wings; moving the stick to the right increases the left wing's amplitude (causing a right turn).
Scale: 40–50% is recommended.

If the scale is too high, both wings may move simultaneously.

Ch 5: Flapping frequency adjustment.

Ch 6: Aileron sub-trim (flight path correction); set using the transmitter's Ch 6 sub-trim.

---------------------------------------------------------------------
# Please obtain information regarding 2ServoFlapSystem from the following site.

2ServoFlapOrnithopter

https://github.com/KazuKaku/2ServoFlapOrnithopter



