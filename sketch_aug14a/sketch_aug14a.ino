int LED =A1;

void setup() {

  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
  analogWrite(LED,HIGH);
  Serial.println("LED HIGH");
  delay(100);
  analogWrite(LED,LOW);
  Serial.println("LED LOW");
  delay(100);
  

}
