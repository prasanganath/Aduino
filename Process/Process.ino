

#include <Process.h>

void setup() {
  
  Bridge.begin();

  
  SerialUSB.begin(9600);


  while (!SerialUSB);

 
  runCurl();
  runCpuInfo();
}

void loop() {
 
}

void runCurl() {
 
  Process p;		
  p.begin("curl");	
  p.addParameter
  p.run();		

  
  while (p.available() > 0) {
    char c = p.read();
    SerialUSB.print(c);
  }
 
  SerialUSB.flush();
}

void runCpuInfo() {
  
  Process p;		
  p.begin("cat");	
  p.addParameter("/proc/cpuinfo"); 
  p.run();		

  
  while (p.available() > 0) {
    char c = p.read();
    SerialUSB.print(c);
  }
 
  SerialUSB.flush();
}
