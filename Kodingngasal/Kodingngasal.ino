#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

#define motor1A 5
#define motor1B 6


void setup(){
  Serial.begin(115200);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);

  
  servo1.attach(A0);
  servo2.attach(A1);
  servo3.attach(A2);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);


}

void loop(){
  
  for(int i=0; i <= 180;i++){
    servo1.write(i);
    servo2.write(i);
    servo3.write(i);
  }
    digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  

}
