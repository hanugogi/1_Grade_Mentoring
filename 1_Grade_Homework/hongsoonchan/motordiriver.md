L298N 모터 드라이버
DC모터의 방향, 속도를 제어하기 위해 사용하는 모듈
댜용량 모터오 최대 2A까지 지원한다.
모듈 한 개로 2개의 모터를 제어 가능

-드라이버 부분의 공급전압 VMS : +5 V ~ 35 V-
-드라이버 부분의 최대전류 : 2A /bridge
-로직 부분의 공급전압 VSS : 4.5 ~ 50.5V
-로직 부분의 작동 전류 범위: 0 ~ 36mA
-입력제어 신호 전압 범위 : H: 4.5 ~ 5.5V / L : 0V
-최대 소비 전력: 20W
-기타 기능 : 방항제어 표시 LED, 전원표시 LED
-무게 : 33g

포트
가운데 파란색 포트(나사 3개)에 전원 연결 순서대로 VMS(+), GND(-), 5V
양옆포트 (나사 2개)들은 모터 연결

제어
ENA와 ENB는 모터 A, B를 Enable(사용) 시킬 것이냐를 결정한다.
아두이노에서 ENA, ENB에 HIGH 전압을 걸어주고 IN1, IN2 입력을 조절해서 모터 방향을 제어할 수 있다.
ENA, ENB에 LOW를 걸어주면 IN1, IN2에 관계없이 정지합니다.
ENA, ENB에 아두이노 PWM 핀(D 3, 5, 6, 9, 10, 11)과 연결하면 모터의 속도를 변경 시킬 수 있다.