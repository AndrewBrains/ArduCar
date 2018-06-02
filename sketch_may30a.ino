#include <Servo.h>

String a;
String throttle, steer;
char val;
Servo steer_servo;
void setup() {
steer_servo.attach(11);
Serial1.begin(9600);
Serial.begin(115200);
throttle = "100";
steer = "90";
pinMode (12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial1.available()>=4) //все команды содержат овно 4 байта, для удобства
  {
    val = char(Serial1.read());
    if (val == 'T'){ throttle = ""; for (int i=1;i<=3;i++) throttle+=char(Serial1.read());}
    if (val == 'S'){ steer = ""; for (int i=1;i<=3;i++) steer+=char(Serial1.read());}
    /*Serial.print("THR ");
    Serial.print(throttle);
    Serial.print("STR ");
    Serial.print(steer);
    Serial.println();
    */
  }
  analogWrite(12,throttle.toInt()-100);
  steer_servo.write((360-steer.toInt())*0.7);
}
