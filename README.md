# 2ServoFlapSystem_on_-ChineseButterflyOrnithopter

Implementing 2ServoFlapSystem on Chinese butterfly ornithopter 

2ServoFlapSystem on Chinese butterfly ornithopter -RP2040 and ppmRX 

Created a 2ServoFlapSystem for a Chinese-made butterfly-shaped Ornithopter.  

Created code that allows for operation similar to the transmitter included with the Chinese Butterfly Ornithopter.

## Compatible boards:

RP2040-Tiny (requires a separate adapter for USB connection)
or RP2040-Zero (supports direct USB-C connection)

## Wiring

Wiring is the same as the RP2040-Tiny setup shown here:
https://github.com/KazuKaku/2ServoFlapOrnithopter

## motion

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
# Next from Github site

https://github.com/KazuKaku/2ServoFlapOrnithopter

## Flight controls for an Ornithopter with a horizontal Tail

![2210830 ServoFlap system of 2 serevo](/image/210830%20ServoFlap%20system%20of%202%20serevo.jpg)

## New Servo Flap System by K.Kakuta

1 Bilateral Servo Flap between Max high point and Max low point

2 Change max flap point (throttle stick 3ch ) 
 
  and change Flapping frequency(5ch)

3 Change center of Flapping angle Horizontal (Ch1 aileron stick) and Vertical (Ch2 elevator stick)

4 Change flapping amplitude on each Servo (Ch4 rudder stick)
Increase flap amplitude of one servo and decrease flap amplitude of another servo

## Setting : 

Set elevator and rudder and aileron stick Center-- 1500microsesond

Set 5Ch at Slider or Volume or other switch

Set throttle stick at low max --1000 microsecond

## Need :
   Small ppm output Receiver(over 5 channels)

   High power High speed Digital Servo

   -----BLUEARROW AF D43S-6.0-MG Micro Metal Gear Digital Servo is best
       
       When using a servo with a high supply voltage (such as HVServo), 
       
                                          please use wiring appropriate for that servo.

   -----Servo Bluearrow AF D43S-6.0-MG Digital Servo (6V input) can be substituted with PTK7350 (6V input or 7.4V input).

   -----Servo Bluearrow D0576HT-HV (7.4V input) can be substituted with PTK7465 (2S Lipo Direct input or 8.4V input).

   Arduino Pro mini board  
   
  ---(Seeed Studio XIAO RP2040 and Waveshare RP2040 Tiny can also be used CODE for RP2040--Pin name change "2" to "D2", "5" to "D5", "6" to "D6")

  ---(Seeed Studio XIAO SAMD21 and Seeed Studio XIAO RP2040, Waveshare RP2040 Tiny work by 6V input)
  
  Lipo
   
   ----Lipo1cell (high discharge rate 20C) and Small StepUp DC converter (3.7V to 6V 1A or 4A) for Bluearrow AF D43S-6.0-MG Digital Servo or PTK7350
   
   ----Or Lipo2cell(direct input) or Lipo2cell and Small Stepdown DC converter (2SLipo to 7.4V or 8.4V) for Bluearrow D0576HT-HV(7.4V input) or PTK7465(direct or 7.4V-8.4V input)

## Wiring

PPM Receiver-- RX PPM signal input to D2 pin

right Servo --D5 pin

left Servo--D6 pin

A 5V on VCC 5Vpin on Arduino pro mini supplied to the RX. or 6V-8.4V to RX direct.

![210811-2 New ServoFlap system  Wiring](/image/210811-2%20New%20ServoFlap%20system%20%20Wiring.jpg)


Ground -GND pin

6V -RAW pin ( 6-6.2V from Stepup DC converter or 7.4V-8.4V from StepDown DC converter or 2S direct)




## Wiring 5V for ppm RX
Wire 5V power supply from Pro Mini Board VCC to 5V ppm RX

![224023 New ServoFlap system for 5VRX  Wiring](/image/224023%20New%20ServoFlap%20system%20for%205VRX%20%20Wiring.jpg)
## My setting

Lipo: 70-150mAh1cell Lipo battery

Servo: BLUEARROW AF D43S-6.0-MG Micro Metal Gear Digital Servo

Arduino Pro mini board

DC step up converter from 1cell Lipo 3.7V to 6V output




## Flap motion and Wing control VTR 
ServoFlapOrnithopterAmericanKestrel112 Flap motion and Flight Control
(https://www.youtube.com/watch?v=uDIVc77CtyM)

## Making VTR 
Making of ServoFlapOrnithopterAmericanKestrel112 
(https://www.youtube.com/watch?v=oznn0DH_pOc)

All List
(https://www.youtube.com/playlist?list=PLErvdRrwWuPooowmNbeGPEB-HlgC26jC-)


## My YouTube channel 
 Various ServoFlapOrnithopters have been uploaded.
(https://www.youtube.com/@BZH07614)

## My Website of ornithopter
 (https://kakutaclinic.life.coocan.jp/HabatakE.htm)

## Request site for production of Kazu Ornithpter
(https://kakutaclinic.life.coocan.jp/KOrniSSt.html)
 


## Flight controls for an Ornithopter without a horizontal Tail (such as a butterfly type)

The operation of the Aileron is the opposite of that for an Ornithopter with a horizontal Tail.

![230706 ServoFlap system of 2 serevo for Butterfly &DragonFly](/image/230706%20ServoFlap%20system%20of%202%20serevo%20for%20Butterfly%20&DragonFly.jpg)


