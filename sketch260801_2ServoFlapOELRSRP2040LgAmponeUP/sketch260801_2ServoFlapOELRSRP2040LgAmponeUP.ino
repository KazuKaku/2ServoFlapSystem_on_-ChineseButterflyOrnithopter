//260622 SFO for 2 servo CODE ELRS by K.Kakuta 
//--use Library CRSFforArduino by Sam4uk https://sam4uk.github.io/libraries/crsf/ https://github.com/sam4uk/CRSF
// 260801 SFO for 2 servo CODE ELRS for chinesButterfy LargeAmp One UP wing

#include <Servo.h>
#include "src/CrsfSerial.h"//#include <CrsfSerial.h>  // ← 追加#include "src/CrsfSerial.h"//


// RP2040-Tiny UARTsetting  ELRS TX--to --RP2040Tiny D1(GP1)
#define CRSF_RX_PIN D1//D1 from ELRS TX
#define CRSF_TX_PIN D0//D0 to ELRS RX  
// Sam4uk CRSF 
CrsfSerial crsf(Serial1, CRSF_BAUDRATE);


int servo_left_pin = D6;
int servo_right_pin = D5;

volatile int elevator = 0;
volatile int flapamp = 0;

volatile float delaytime = 100;// Servo speed low-increase Servo speed high-decrease this.
                          // unit: micro second
float elapsed_time = 0;
float dt;
unsigned long current_time, prev_time;

volatile int ch3value = 1000;//Ch3
volatile int ch1value = 1500;//Ch1
volatile int ch2value = 1500;//Ch2
volatile int ch4value = 1500;//Ch4: Set Scale of 4ch of TX to 70%
volatile int ch5value = 1500;//Ch5
volatile int ch6value = 1500;//Ch6
volatile int ch7value = 1500;//Ch6
static int servo_comm1 = 0;// Left or Right Servo high point and low point
static int servo_comm2 = 0; // Left or Right Servo high point and low point
volatile int rudder = 0;
float glide_deg = 0; // Gliding angle 0=0 degree 500=90degree
static float servo_zero1 = 0;//flap angle adjust
static float servo_zero2 = 0; //flap angle adjust
static int rtrudder = 0; //Rt rudder
static int ltrudder = 0; //Lt rudder
Servo servo_left, servo_right; // create servo object to control a servo

void packetChannels()
{
  // CRSF from 1ch
  ch1value = crsf.getChannel(1);
  ch2value = crsf.getChannel(2);
  ch3value = crsf.getChannel(3);
  ch4value = crsf.getChannel(4);
  ch5value = crsf.getChannel(5);
  ch6value = crsf.getChannel(6);
  ch6value = crsf.getChannel(7);

  Serial.print("CH1-7 us: ");
  Serial.print(ch1value); Serial.print(", ");
  Serial.print(ch2value); Serial.print(", ");
  Serial.print(ch3value); Serial.print(", ");
  Serial.print(ch4value); Serial.print(", ");
  Serial.print(ch5value); Serial.print(", ");
  Serial.print(ch6value); Serial.print(", ");
  Serial.println(ch7value);

}


void setup() {
  Serial.begin(115200);

  pinMode(servo_left_pin, OUTPUT);
  pinMode(servo_right_pin, OUTPUT);

  servo_left.attach(servo_left_pin);//output pin No
  servo_right.attach(servo_right_pin); //output pin No
delay(2000);//Avoid abnormal positions at startup-wait 2 second until RX starts220306

// CRSF Initialization
  Serial1.setRX(CRSF_RX_PIN);
  Serial1.setTX(CRSF_TX_PIN);
  Serial1.begin(CRSF_BAUDRATE);  // 420000bps

  crsf.begin();
  crsf.onPacketChannels = &packetChannels;

  Serial.println("CRSF input, ch1-7 = 1000-2000us");

}

void loop() {
// ★ CRSF intake
  crsf.loop();


prev_time = current_time;      
  current_time = micros();      
  dt = (current_time - prev_time)/1000000.0;

  elapsed_time = elapsed_time + dt; // total time spent in the main loop since beginning one upstroke/downstroke

 rudder=(int)(ch7value-1500);//C7  Flap angle incline-trim- AileronStick

 elevator=(int)(ch2value-1500);//Ch2 Flap Angle bilateral UP&Down
 flapamp=(int)(ch4value-1500);//Ch4 Right and left Flap angle difference from3to2
 delaytime=(int)((ch6value-950)/5);//Ch6 Flapping frequency 
// you can change UP or Down direction by your transmitter Reverse setting of each Channel

    //Serial.print("rudder");Serial.print(rudder);
    //Serial.print(",\t");
    //Serial.print("elevator");Serial.print(elevator);
    //Serial.print(",\t");
    //Serial.print("flapamp");Serial.print(flapamp);
//Serial.print(",\t");
    //Serial.print("delaytime");Serial.print(delaytime);
    //Serial.print(",\t");

 if (ch3value > 1080) {
if (elapsed_time < delaytime/1000) {

  servo_comm1 = (int)( (ch3value -1000)/1.12+1500 + rudder - elevator+ servo_zero1+ flapamp + ltrudder );
  servo_comm2 = (int)(1000 + (2000 - ((ch3value -1000)/1.12+1500)) + rudder + elevator- servo_zero2+flapamp + rtrudder);  
   //The servo's operating range is currently set to 1000–2000 μs, but changing the "2" to "1.12" extends the range to approximately 600–2400 μs. 
   // This configuration is more effective for butterfly-style ornithopters.

  servo_left.writeMicroseconds(servo_comm1); // servo position in variable 'pos'
  servo_right.writeMicroseconds(servo_comm2); // servo position in variable 'pos'
}

if ((elapsed_time > delaytime/1000) && ( elapsed_time < (delaytime + delaytime)/1000)) {

servo_comm1 = (int)( (ch3value -1000)/1.12+1500 + rudder + elevator+ servo_zero1-flapamp + rtrudder);
  servo_comm2 = (int)(1000 + (2000 - ((ch3value -1000)/1.12+1500)) + rudder - elevator- servo_zero2-flapamp + ltrudder);  

  servo_left.writeMicroseconds(servo_comm2); // servo position in variable 'pos'
  servo_right.writeMicroseconds(servo_comm1); // servo position in variable 'pos'

      //Serial.print("servo_comm1");Serial.print(servo_comm1);
    //Serial.print(",\t");
    //Serial.print("servo_comm2");Serial.print(servo_comm2);
    //Serial.println(",\t");
  

 }

  }
else{
  
  servo_comm1=(int)(1500+rudder-elevator+glide_deg + ltrudder);
  servo_comm2=(int)(1500+rudder+elevator-glide_deg + rtrudder);  

  servo_left.writeMicroseconds(servo_comm1); // servo position in variable 'pos'
  servo_right.writeMicroseconds(servo_comm2); // servo position in variable 'pos' 

    //Serial.print("servo_comm1");Serial.print(servo_comm1);
    //Serial.print(",\t");
    //Serial.print("servo_comm2");Serial.print(servo_comm2);
    //Serial.println(",\t");

}
     if (elapsed_time > (delaytime + delaytime)/1000) {// one full flap is finisheddt
         elapsed_time = 0; // start next flapping cycle
}

}

