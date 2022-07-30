#include <Servo.h>
// initializing servo to both motor functions and base angles
Servo base;
Servo shoulder;

int base_angle = 90;
int shoulder_angle = 90;

void setup() {
  Serial.begin(9600);

  base.attach(9);
  shoulder.attach(10);

  base.write(base_angle);
  shoulder.write(shoulder_angle);
}

void loop() {
  String command = Serial.readString();
  // Change the angle based on the command
  if (command == "فوق" || command == "أعلى" || command == "توب") {
    shoulder_angle = shoulder_angle - 45;
    shoulder.write(shoulder_angle);
  }
  else if (command == "تحت" ||command == "أسفل" || command == "بوتوم") {
    shoulder_angle = shoulder_angle + 45;
    shoulder.write(shoulder_angle);
  }
  else if (command == "يمين" || command == "رايت") {
    base_angle = base_angle - 45;
    base.write(base_angle);
  }
  else if (command == "يسار" || command == "ليفت") {
    base_angle = base_angle + 45;
    base.write(base_angle);
  }
  //Serial.println(shoulder_angle);
  //Serial.println(base_angle);
  delay(1000);
}
