int L = 12;
int E = 13;
int f =11;
int g =10;
int h=9;
void setup() {

  pinMode(L,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
}

void loop() {
  
  digitalWrite(L,HIGH);
  delay(100);
  digitalWrite(L,LOW);
  delay(30);
  digitalWrite(E,HIGH);
  delay(100);
  digitalWrite(E,LOW);
  delay(30);
  digitalWrite(f,HIGH);
  delay(100);
  digitalWrite(f,LOW);
  delay(30);
  digitalWrite(g,HIGH);
  delay(100);
  digitalWrite(g,LOW);
  delay(50);
  digitalWrite(h,HIGH);
  delay(100);
  digitalWrite(h,LOW);
  delay(30);
  
}
