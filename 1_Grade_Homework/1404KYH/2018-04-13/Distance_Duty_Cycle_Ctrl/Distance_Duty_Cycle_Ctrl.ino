const int Echo = 2;
const int MOTOR = 3;
const int Trig = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trig, LOW);
  digitalWrite(Echo, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  long reflection = pulseIn(Echo, HIGH);
  float distance = reflection / 58.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  int motorconv = map((int)distance, 0, 3000, 0, 255);

  analogWrite(MOTOR, (int)motorconv);

}
