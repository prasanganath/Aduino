

#include <ArduinoRobot.h>
#include <Wire.h>

void setup() {
 
  Robot.begin();
}

void loop() {
  Robot.motorsWrite(255, 255);  
  delay(2000);
  Robot.motorsStop();           
  delay(1000);
  Robot.motorsWrite(-255, -255); 
  delay(1000);
  Robot.motorsWrite(0, 0);      
  delay(1000);
  Robot.motorsWrite(-255, 255); 
  delay(2000);
  Robot.motorsStop();          
  delay(1000);
  Robot.motorsWrite(255, -255); 
  delay(2000);
  Robot.motorsStop();           
  delay(1000);
}
