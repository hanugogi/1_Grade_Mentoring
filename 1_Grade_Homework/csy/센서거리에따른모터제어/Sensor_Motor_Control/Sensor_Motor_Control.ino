int Trig =3, Echo=2; //trig는 초음파를 쏘는곳 echo는 초음파를 받는곳
int MOTOR=4;
void setup() {
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  pinMode(MOTOR,OUTPUT);

}

void loop() {
  digitalWrite(Trig,LOW);
  digitalWrite(Echo,LOW);
  delayMicroseconds(2); //잡음 제거를 위한 안정화 (오류가 생길수 있음)

  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW); //초음파 10us동안 발생

  long reflection=pulseIn(Echo,HIGH); //펄스의 HIGH 측정된 시간 저장 
  float distance = reflection /58.0;

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("cm ");

  int speed = map(distance,0,3000,0,255);
  analogWrite(MOTOR,speed);
}
