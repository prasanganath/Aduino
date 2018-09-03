void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
 
}
void loop() {
  int i=1;
  int q=4;
 for(i=1; i<5; i++){
  digitalWrite(i,HIGH);
  delay(1000);
  digitalWrite(i,LOW);
  delay(10);
   digitalWrite(i+1,HIGH);
  delay(1000);
  digitalWrite(i+1,LOW);
  delay(10);
  
  
 }
    for(q=4; q>0; q--){
    digitalWrite(q,HIGH);
    delay(50);
    digitalWrite(q,LOW);
    delay(10);
    }
  }
 

