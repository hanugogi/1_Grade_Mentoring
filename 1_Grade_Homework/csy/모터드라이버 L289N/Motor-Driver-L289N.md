**모터드라이버L289N**
====================

###모터드라이버란?
--------------
- 모터의 제어가 필요한 프로젝트를 진행 할 시 필수적으로 모터 드라이버 모듈이 사용
- 모터 드라이버는 모터의 속도, 정방향, 역방향 회전 등을 아두이노의 프로그래밍을 통해서 제어
 - 홈오토메이션이나 로봇 등의 제어에도 사용할 수 있음
 - 홈오토메이션이란? 주택의 안락함,편의성,보안,에너지효율성이 가족구성원에 효율적으로 맞춰지는 것
- 블루투스 모듈, 와이파이 모듈 등을 결합한다면 모터의 원격조종도 가능
- 모터 드라이버는 아두이노를 보조해주는 역할
 - 아두이노 보드는 프로그램으로 전기신호(PWM)를 제어하기 위한 마이크로컨트롤러 보드
 - 아두이노 보드에 프로그램을 넣어 전기신호를 제어함으로써 모터에 입력되는 전원의크기를 제어모터의 방향 및속도를 제어
 - 모터는 보통 아두이노와 같은 마이크로컨트롤러가 허용하는 전류보다 전류를 많이사용하기 때문에 추가적인 회로가 필요하며 그역할을 해주는 것이 모터드라이버
 
###DC모터
----------
- DC모터는 2개의 단자가 있으며, 단자에 +, - 극을 연결하여 전원을 입력할 경우 모터가 작동 
  - DC모터는 극이 없으며, 전원을  반대로 연결할경우 반대로 회전하는 성질 존재
 - 또한 입력되는 전원(전압)의 크기에 따라 회전수와 힘이 조절됩니다. (전원과 회전수 및 힘은 비례함)

###스텝모터
-----------
- 모터의 회전을 잘게 쪼개서 쪼갠 조각(스텝)을 이용해서 제어하는 모터
- 스텝모터는 펄스(Puls)에 의해 디지털적으로 제어하기 때문에 정밀한 제어가 가능
 - 아두이노, 라즈베리파이등으로 동작시키기에 편리
- 제어부가 비교적 간단해서 가격이 저렴하고 브러시리스(Brushless)모터이기 때문에 오래 사용할 수 있다는 장점이 존재

###모터드라이버L298N모듈
------------------------

####형태
- 가운데에 커다랗게 L298N 칩이 커다란 방열판과 함께 위치
- 좌측과 우측에 각각 모터의 연결을 위한 아웃풋 단자 존재 
- 앞쪽에는 모터를 구동하기 위한 외부전원 입력 단자(12V 입력)존재
- 우측에는 아두이노와 연결하여 컨트롤 하기 위한 단자들(ENA,IN1,IN2,IN3,IN4,ENB) 존재  
 - ENA: PWM신호를 입력하여 모터A의 속도제어
 - IN1,IN2: 디지털신호로 모터A의 방향제어
 - IN3,IN4: 디지털신호로 모터B의 방향제어
 - ENB: PWM신호를 입력하여 모터B의 속도제어
- 5V 레귤레이터에 의해 출력되는 5V 출력단자가 있어서 아두이노 등의 전원으로 활용 가능 
 - 레귤레이터 - 전압을 변환해주는 부품이다.
 - 리니어 레귤레이터 
 		- 3단계직접적으로 전압을 조절한다.
         - 열 발생량이 크다.
         - 전력 효율이 낮다.
         - 요규 전력량이 낮은 곳에 많이 사용된다.
   - 스위칭 레귤레이터 
 		- 펄스를 조절해 전압을 조절한다.
        - 열 발생량이 작다.
        - 요구 전력량이 높은 곳에 많이 사용
        - 회로가 복잡해 비용이 많이 든다.

 
####제어
 - 이 모듈은 2개의 DC모터 제어할 수 있으며 1개의 스텝모터를 제어 가능 
 - 모터 A, B의 정회전, 역회전과 함께 속도조절이 가능
  - 끝의 단자인 ENA, ENB의 핀을 제거하고 아두이노 PWM 단자에 연결하면 analogWrite를 이용하여 0~255 단계로 모터의 속도를 조절 할 수 있다. 
  		- ex)즉 analogWrite(PIN번호, 127)을 하게 되면 모터는 절반의 속도로 회전                                 

####성능
 - L298N 모터 드라이버는 5~35V에 해당되는 DC모터 2개 혹은 스텝모터 1개를 제어하며 각 모터당 2A의 연속 전류를 허용 
 - 성능에 비해 가격이저렴하기 때문에 부담없이 사용할 수 있으며, 아두이노의 5V출력 혹은 외부전원을 입력받아 모터에 공급 
  - 아두이노의 5V핀에 연결할 경우 ~5V ~300mA 모터까지 사용
  - 외부 전원을 입력할 경우 전압 5~35V / 전류 ~2A 모터를 사용할 수 있습니다. (외부 전원이 받쳐준다는 전제하에)

####소스
 - ⇒기본 원리는 L298N의 IN1 단자에 신호가 걸리면 모터A가 정회전/ IN2 단자에 신호가 걸리면 역회전
  - 모터B의 경우도 마찬가지이다. (IN3-정회전, IN4-역회전)

 -예제
 -//모터A 컨트롤
int IN1=7;
int IN2=6;
 
//모터B 컨트롤
int IN3=5;
int IN4=4;
 
void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}
 
void loop() {
  bothMotorStart();
  delay(3000);
  turnLeft();
  delay(3000);  
  turnRight();
  delay(3000);
  motorA_Rotation();
  delay(3000);
  motorB_Rotation();
  delay(3000);
  motorA_Reverse();
  delay(3000);
  motorB_Reverse();
  delay(3000);
  stopAllMotor();
  delay(3000);
}
 
//모터A,B 정회전
void bothMotorStart()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A,B Stop
void stopAllMotor()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B 정회전
void turnLeft()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A 정회전, 모터B 역회전
void turnRight()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
 
//모터A 정회전, 모터B Stop
void motorA_Rotation()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 정회전
void motorB_Rotation()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B Stop
void motorA_Reverse()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 역회전
void motorB_Reverse()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
 
출처
-----
- Link: http://makeshare.org/bbs/board.php?bo_table=arduinomotor&wr_id=12 [make share]
- Link: http://deneb21.tistory.com/277 [Do It Yourself!]
- Link: 아두이노 - 스텝모터|작성자 3DEMP
- Link: https://namu.wiki/w/%EB%A0%88%EA%B7%A4%EB%A0%88%EC%9D%B4%ED%84%B0#s-3 [나무위키-레률레이터] 