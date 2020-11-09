#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo;
int TxD = 11; //white
int RxD = 10; //blue
int servoPosition;
int servoPos;
int new1;
SoftwareSerial bluetooth(TxD, RxD);

void setup() {
  int pos = 0;
  myServo.attach(13);
  //myServo.write(0);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  Serial.println(bluetooth.available());
  if (bluetooth.available()) {
    String value = bluetooth.readString();
    servoPosition = value.toInt();

    if (value.toInt() == 0) {
      Serial.println(servoPosition);
      myServo.write(0);
    }

    if (value.toInt() == 90) {
      Serial.println(servoPosition);
      myServo.write(90);
    }

    if (value.toInt() == 180) {
      Serial.println(servoPosition);
      myServo.write(180);
    }

    while (value.toInt() == 1) {
      if (bluetooth.available())
      {
        value = bluetooth.readString();
        Serial.println(value);

        if (value.toInt() == 2)
        {
          Serial.println("YYY");
          break;
        }
      }
      servoPos++;
      delay(30);
      Serial.println(servoPos);
      myServo.write(servoPos);

      if (servoPos == 180 )
      {
        servoPos = 0;
        break;
      }
    }
  }
}
