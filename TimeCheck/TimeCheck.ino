

#include <Process.h>

Process date;                 
int hours, minutes, seconds;  
int lastSecond = -1;          

void setup() {
  Bridge.begin();        
  SerialUSB.begin(9600);    

  while (!Serial);             
  SerialUSB.println("Time Check"); 

  
  if (!date.running()) {
    date.begin("date");
    date.addParameter("+%T");
    date.run();
  }
}

void loop() {

  if (lastSecond != seconds) { 
   
    if (hours <= 9) {
      SerialUSB.print("0");  
    }
    SerialUSB.print(hours);
    SerialUSB.print(":");
    if (minutes <= 9) {
      SerialUSB.print("0");  
    }
    SerialUSB.print(minutes);
    SerialUSB.print(":");
    if (seconds <= 9) {
      SerialUSB.print("0"); 
    }
    SerialUSB.println(seconds);

 
    if (!date.running()) {
      date.begin("date");
      date.addParameter("+%T");
      date.run();
    }
  }

  while (date.available() > 0) {
   
    String timeString = date.readString();

    int firstColon = timeString.indexOf(":");
    int secondColon = timeString.lastIndexOf(":");

    String hourString = timeString.substring(0, firstColon);
    String minString = timeString.substring(firstColon + 1, secondColon);
    String secString = timeString.substring(secondColon + 1);

    hours = hourString.toInt();
    minutes = minString.toInt();
    lastSecond = seconds;        
    seconds = secString.toInt();
  }

}
