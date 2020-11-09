#include <Servo.h>
#include <AltSoftSerial.h>



AltSoftSerial altSerial;


Servo servoLeft;
Servo servoRight;

void setup() {
  pinMode(3, OUTPUT);
  servoLeft.attach(13);
  servoRight.attach(12);
  Serial.begin(9600);
  /**while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }**/
  altSerial.begin(9600);
}

void loop() {
  char inByte;
  int sensorReading1 = analogRead(A4);
  //Serial.println(sensorReading1);
  if (sensorReading1 <= 300) {
    digitalWrite(3, HIGH);
  } 
  else {
    digitalWrite(3, LOW);
  }
  
 if (altSerial.available()) {
    inByte = altSerial.read();
    Serial.println(inByte);
    Serial.write(inByte);
  }
  
  int sensorReading2 = analogRead(A3);
  if (sensorReading2 > 568) {
 
      { //check if any data is available at the serial port
        char data = Serial.read(); //read and then store data from board in "data" variable
        switch(data) //compare data with switch statement, to do if X is this do this, if x is that do that
          { 
            case 'Z':
              servoRight.writeMicroseconds(1600);
              servoLeft.writeMicroseconds(1400);
              delay(1000);
            case 'z': 
              servoRight.writeMicroseconds(1500);
              servoLeft.writeMicroseconds(1500);
              delay(1000);
            case 'Y': 
              servoRight.writeMicroseconds(1400);
              servoLeft.writeMicroseconds(1600);
              delay(1000);
            case 'y': 
              servoRight.writeMicroseconds(1500);
              servoLeft.writeMicroseconds(1500);
              delay(1000);
          }
          Serial.println(data);
      }
      delay(50);
  }
  else if (sensorReading2 <= 568 && sensorReading2 > 284) {
    if(Serial.available()>0) 
      { 
        char data = Serial.read(); 
        switch(data) 
          { 
            case 'Z':
              servoRight.writeMicroseconds(1550);
              servoLeft.writeMicroseconds(1450);
              delay(1000);
            case 'z': 
              servoRight.writeMicroseconds(1500);
              servoLeft.writeMicroseconds(1500);
              delay(1000);
            case 'Y': 
              servoRight.writeMicroseconds(1450);
              servoLeft.writeMicroseconds(1550);
              delay(1000);
            case 'y': 
              servoRight.writeMicroseconds(1500);
              servoLeft.writeMicroseconds(1500);
              delay(1000);
          }
          
      }
      delay(50);
  }
  else {
    if(Serial.available()>0) 
      { //check if any data is available at the serial port
        char data = Serial.read(); //read and then store data from board in "data" variable
        switch(data) //compare data with switch statement, to do if X is this do this, if x is that do that
          { 
            case 'Z':
              servoRight.writeMicroseconds(1525);
              servoLeft.writeMicroseconds(1475);
              delay(1000);
            case 'z': 
              servoRight.writeMicroseconds(1500);
              servoLeft.writeMicroseconds(1500);
              delay(1000);
            case 'Y': 
              servoRight.writeMicroseconds(1475);
              servoLeft.writeMicroseconds(1525);
              delay(1000);
            case 'y': 
              servoRight.writeMicroseconds(1500);
              servoLeft.writeMicroseconds(1500);
              delay(1000);
          }
          Serial.println(data);
      }
  delay(50);
  }

}
