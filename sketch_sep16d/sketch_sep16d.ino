char val;
void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
    val=Serial.read();
    Serial.println(val);
  }
  
  if(val=='1'){
  int i=1;
  int q=4;
 for(i=1; i<5; i++){
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  delay(10);
   digitalWrite(i+1,HIGH);
  delay(1000);
  digitalWrite(i+1,LOW);
  delay(10);
 }
  for(q=4; q>0; q--){
    digitalWrite(q,HIGH);
    delay(100);
    digitalWrite(q,LOW);
    delay(10);
    }
  }
  else if(val=='2'){
    digitalWrite(2,HIGH);
  }
  else if(val=='3'){
    digitalWrite(13,LOW);
  }
  else if(val=='4'){
    digitalWrite(2,LOW);
  }
  delay(100);
    
  }


