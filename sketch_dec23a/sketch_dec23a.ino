
#include<Servo.h>
Servo sandun;
void setup() {
  sandun.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=1;i<=360;i++){
    sandun.write(i);
    delay(5);
  }





  
 
  
  

}
