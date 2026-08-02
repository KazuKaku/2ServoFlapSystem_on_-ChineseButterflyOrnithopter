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

PPM RX　　sketch_260731SFOfor2ServoV4RP2040LgAmpOneUP

![Wiringppm](https://github.com/KazuKaku/2ServoFlapSystem_on_-ChineseButterflyOrnithopter/blob/cd36bb3f3799a0289254164455a0e6dc043d0688/image/RP2040-Tiny%20Wiring%20%202SF%20ppm.jpg)

ELRS RX　　sketch260801_2ServoFlapOELRSRP2040LgAmponeUP

![WiringELRS](https://github.com/KazuKaku/2ServoFlapSystem_on_-ChineseButterflyOrnithopter/blob/8092b29b86531493b4d124b12c18665ab4ee7c3b/image/RP2040TinyWiring2SFSELRS.jpg)


ppm RX and Arduino board   

   Wiring of ppm RX and Arduino board 

   -- look next site
    
https://github.com/KazuKaku/2ServoFlapOrnithopter



## Wing motion

Refer to the video below for operation. Note that the trim setting method differs.

CODE  for Chinese Butterfly Ornithopter

https://youtu.be/7gkWegeKj8Q

## setting
Because the servo mounting configuration on the Chinese-made butterfly ornithopter differs from the standard setup, the servo connections are reversed.

Connect D5 (Right Servo) to the left servo on the ornithopter body.

Connect D6 (Left Servo) to the right servo on the ornithopter body.

## Setting of Transmitter 

Ch 1: Moving the stick to the right raises the right wing; the left wing remains stationary. Scale: 30–40%.

　　Keep the center value for Channel 1 at 1500 μs.

　　Adjust the wing tilt using the trim for Channel 6.

　　Adjust the dihedral angle using the trim for Channel 2.

Ch 2: Moving the stick down lowers both wings. Scale: 30–40%.

　　Remove the servo horn and adjust the setting so that the center value is as close to 1500 μs as possible.

Ch 3: Throttle; moving it up increases the flapping amplitude.

Ch 4: Difference in flapping amplitude between left and right wings; moving the stick to the right increases the left wing's amplitude (causing a right turn).

　　Scale: 40–50% is recommended.

　　If the scale is too high, both wings may move simultaneously.

ppm RX : Ch 5: Flapping frequency adjustment.

ELRS RX : Ch 6: Flapping frequency adjustment.

ppm RX Ch 6: Aileron sub-trim (flight path correction); set using the transmitter's Ch 6 sub-trim.

ppm RX Ch 7: Aileron sub-trim (flight path correction); set using the transmitter's Ch76 sub-trim.

---------------------------------------------------------------------
# Please obtain information regarding 2ServoFlapSystem from the following site.

2ServoFlapOrnithopter

https://github.com/KazuKaku/2ServoFlapOrnithopter



