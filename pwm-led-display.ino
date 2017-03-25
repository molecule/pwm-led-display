/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  PWM test - this will drive 16 PWMs in a 'wave'

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm40 = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm41 = Adafruit_PWMServoDriver(0x41);

void setup() {
  
  Serial.begin(9600);
  Serial.println("16 channel PWM test!");

  pwm41.begin();
  pwm41.setPWMFreq(1000);  // This is the maximum PWM frequency
  // red LEDS, at freq = 20, I can't notice the LEDs flickering. At 10 I definitely can.
  pwm40.begin();
  pwm40.setPWMFreq(1000);  // This is the maximum PWM frequency
  // for green LEDs, at freq = 20 I can definitely notice flickering. At 80 it is ok.
}

void loop() {
  // Drive each PWM in a 'wave'
  // increasing the amount "i" is incremented by speeds up the animation.
  for (uint16_t i=0; i<4096; i += 32) {
    for (uint8_t channel=0; channel < 16; channel++) {
      //                     on    off
      //pwm41.setPWM(channel, 0, (i + (4096/16)*channel) % 4096 );
      //pwm40.setPWM(16-channel, 0, (i + (4096/16)*channel) % 4096 );
      pwm41.setPin(channel, (i + (1024/16)*channel) % 4096);
      pwm40.setPin(channel, (i + (1024/16)*channel) % 4096);
    }
  }
}
