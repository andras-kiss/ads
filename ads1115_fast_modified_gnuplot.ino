#include <Wire.h>
#include <I2Cdev.h>
#include <ADS1115.h> // from https://github.com/jrowberg/i2cdevlib/blob/master/Arduino/ADS1115/ADS1115.h

const long interval = 2000;
unsigned long previousMicros = 0;

ADS1115 adc0(ADS1115_ADDRESS_ADDR_GND); 

void setup(void)
{
  Serial.begin(230400);
  Wire.begin();
  adc0.initialize();
  adc0.showConfigRegister();
  adc0.setRate(ADS1115_RATE_860);         //860 samples/sec
  adc0.setMode(ADS1115_MODE_CONTINUOUS);  //continuous sampling
  // adc0.setGain(ADS1115_PGA_6P144);     //2/3x gain +/- 6.144V  1 bit = 0.1875mV    22MΩ  //start up default
  // adc0.setGain(ADS1115_PGA_4P096);     //1x gain   +/- 4.096V  1 bit = 0.125mV     15MΩ
  // adc0.setGain(ADS1115_PGA_2P048);     //2x gain   +/- 2.048V  1 bit = 0.0625mV    4.9MΩ // default for this library
  adc0.setGain(ADS1115_PGA_1P024);        //4x gain   +/- 1.024V  1 bit = 0.03125mV   2.4MΩ
  // adc0.setGain(ADS1115_PGA_0P512);     //8x gain   +/- 0.512V  1 bit = 0.015625mV  710kΩ
  // ads.setGain(ADS1115_PGA_0P256);      //16x gain  +/- 0.256V  1 bit = 0.0078125mV 710kΩ
  adc0.setMultiplexer(ADS1115_MUX_P0_N1); //sets mux to differential
}

void loop(void)
{  
  unsigned long currentMicros = micros();
  if (currentMicros - previousMicros >= interval)
  {
    //Serial.print(currentMicros-previousMicros);
    //Serial.print(' ');
    previousMicros = currentMicros;
    Serial.println(adc0.getMilliVolts(),3);
  }
}

//cat /dev/ttyUSB0 460800 | awk '{printf "\n%.3f %i", NR/500,$1}' > data.dat
