  char val;
void setup() {
 pinMode(13,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
    val=Serial.read();
    Serial.println(val);
  }
  if(val=='1'){
    digitalWrite(13,HIGH);
  }
  else if(val=='2'){
    digitalWrite(13,LOW);  
  }
  delay(100); 

}
