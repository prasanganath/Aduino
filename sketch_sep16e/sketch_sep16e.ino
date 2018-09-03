#define trig 2
#define echo 4
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long t = pulseIn(echo,HIGH);
  long inches = t/74/2;
  long cm = t/29/2;

  Serial.print(inches);
  Serial.print("in \t");
  Serial.print(cm);
  Serial.print("cm\n");
  // put your main code here, to run repeatedly:
  if(inches<3){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  delay(10);

}
