#include <Servo.h>

Servo servo1; // jepit
Servo servo2; // angkat
Servo servo3; // belok

#define motor1A 5
#define motor1B 6

String command = "";

void setup() {
  Serial.begin(115200);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);

  servo1.attach(A0);
  servo2.attach(A1);
  servo3.attach(A2);

  servo1.write(0);   // posisi awal jepit
  servo2.write(0);  // posisi netral angkat
  servo3.write(90);  // posisi tengah belok
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "maju") {
      Serial.println("Gerak Maju");
      digitalWrite(motor1A, HIGH);
      digitalWrite(motor1B, LOW);
    }

    else if (command == "mundur") {
      Serial.println("Gerak Mundur");
      digitalWrite(motor1A, LOW);
      digitalWrite(motor1B, HIGH);
    }

    else if (command == "berhenti") {
      Serial.println("Stop");
      digitalWrite(motor1A, LOW);
      digitalWrite(motor1B, LOW);
    }

    else if (command == "kanan") {
      Serial.println("Belok Kanan");
      servo3.write(40);  // belok kanan
      delay(100);
    
    }

    else if (command == "kiri") {
      Serial.println("Belok Kiri");
      servo3.write(140);   // belok kiri
      delay(100);
    
    
    }

    else if (command == "mengangkat") {
      Serial.println("Mengangkat");
      servo2.write(90);   // angkat ke -60° dari netral
    }

    else if (command == "menurunkan") {
      Serial.println("Menurunkan");
      servo2.write(-90);   // kembali ke posisi netral
    }

    else if (command == "menjepit") {
      Serial.println("Menjepit");
      servo1.write(40);   // jepit (ubah sesuai kebutuhan)
    }
     
    else if (command == "membuka") {
      Serial.println("Membuka");
      servo1.write(-40);   // jepit (ubah sesuai kebutuhan)
    }

    else {
      Serial.println("Perintah tidak dikenali");
    }
  }
}
