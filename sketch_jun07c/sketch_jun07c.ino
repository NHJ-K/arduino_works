
#include <SPI.h>

#include <EmonLib.h> 
 
#define ANALOG_INPUT_SENSOR D1  // The digital input you attached your SCT sensor.  (Only 2 and 3 generates interrupt!)
//#define INTERRUPT DIGITAL_INPUT_SENSOR-2 // Usually the interrupt = pin -2 (on uno/nano anyway)


EnergyMonitor emon1;

long wattsum = 0;
double kwh = 0;
double wh = 0;
long lastmillis = 0;
int minutes = 0;


void setup()  
{  
  
  Serial.begin(115200);
  emon1.current(ANALOG_INPUT_SENSOR, 25);             // Current: input pin, calibration.



}


void loop()     
{ 
  
  
  
  if (millis()-lastmillis > 5000) {
    double Irms = emon1.calcIrms(1480);  // Calculate Irms only
    if (Irms < 0.3) Irms = 0;
    long watt = Irms*240.0;
    wattsum = wattsum+watt;
    minutes = minutes + 1;
    lastmillis = millis();
    Serial.print(watt);         // Apparent power
    Serial.print(" ");
    Serial.println(Irms);          // Irms
  
  }
  if (minutes == 10) {
    wh = wh + wattsum/10;
    kwh = wh/1000;
    
    wattsum = 0;
    minutes = 0;
  }

}
