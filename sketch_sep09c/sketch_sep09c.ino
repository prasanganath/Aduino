char val;
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    val=Serial.read();
    Serial.println(val);
  }

  if (val=='1'){
    digitalWrite(13,HIGH);
  }else if(val=='2'){
    digitalWrite(13,LOW);
  }else if (val=='3'){
    while (true){
      digitalWrite(13,HIGH);
      delay(100);
      digitalWrite(13,LOW);
      delay(100);
    }
  }
}
