#include <Wire.h>
#include <I2Cdev.h>
#include <ADS1115.h> // from https://github.com/jrowberg/i2cdevlib/blob/master/Arduino/ADS1115/ADS1115.h


ADS1115 adc0(ADS1115_ADDRESS_ADDR_GND); 
float scalefactor = 0.0625; // change this to match your amplifier settings
float millivolts = 0.0; // The result of applying the scale factor to the raw value
float time;

int16_t start;
int16_t elapsed;
uint16_t currentADCreadings;  

void setup(void)
{
  Serial.begin(115200);  
  Wire.begin();
  adc0.initialize(); // initialize ADS1115 16 bit A/D chip
  //Serial.println(adc0.testConnection() ? "ADS1115 connection successful" : "ADS1115 connection failed");  


  // To get output from this method, you'll need to turn on the 
  //#define ADS1115_SERIAL_DEBUG // in the ADS1115.h file
  adc0.showConfigRegister();
  adc0.setRate(ADS1115_RATE_860);  //860 samples/sec
  adc0.setMode(ADS1115_MODE_CONTINUOUS);  //continuous sampling

  //                                                                 ScaleFactor  D.Input Impedance 
  // ads.setGain(ADS1115_PGA_6P144);  // 2/3x gain +/- 6.144V  1 bit = 0.1875mV    22MΩ        //start up default
  //adc0.setGain(ADS1115_PGA_4P096);  // 1x gain   +/- 4.096V  1 bit = 0.125mV     15MΩ
  adc0.setGain(ADS1115_PGA_2P048);  // 2x gain   +/- 2.048V  1 bit = 0.0625mV    4.9MΩ       // default for this library
  // ads.setGain(ADS1115_PGA_1P024);  // 4x gain   +/- 1.024V  1 bit = 0.03125mV   2.4MΩ
  // ads.setGain(ADS1115_PGA_0P512);  // 8x gain   +/- 0.512V  1 bit = 0.015625mV  710kΩ
  // ads.setGain(ADS1115_PGA_0P256);  // 16x gain  +/- 0.256V  1 bit = 0.0078125mV 710kΩ

  adc0.setMultiplexer(ADS1115_MUX_P0_N1);   // sets mux to differential
}

void loop(void)
{  
  time = 0.001 * millis();
  currentADCreadings=adc0.getConversion(); //it takes 1.16 ms for the ADC to do a new conversion
  //delayMicroseconds(450); //tweak this delay until your loop takes around 588ms for 500 readings
  Serial.print(time,4);
  Serial.print(' ');
  Serial.println(adc0.getMilliVolts(),4);
  //delay(1000);
} 


