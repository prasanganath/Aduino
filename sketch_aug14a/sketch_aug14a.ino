int LED =A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED,HIGH);
  Serial.println("LED HIGH");
  delay(100);
  analogWrite(LED,LOW);
  Serial.println("LED LOW");
  delay(100);
  

}
