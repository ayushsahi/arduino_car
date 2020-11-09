// Ayush Sahi -- Arduino Car Bot -- Class APTEJ4M - Final Performance Task


#include <Servo.h>
#include <SoftwareSerial.h>

Servo LeftServo;
Servo RightServo;

// Global variables
int input = 0;                  // variable created for capturing input from remote control
int prevInput = 0;
int speed = 0;                  // variable for bot speed ( 1 is Fast, 2 is medium, and 3 is slow)
//Set default speed to Slow if Potentiometer fails
const int leftServoPin = 13;    // the control signal for the left servo
const int rightServoPin = 12;   // the control signal for the right servo
const int ledPin = 6;           // the control signal for the LED
const int buzzerPin = 9;        // the control signal for the Buzzer

SoftwareSerial mySerial(10, 11); // Initialize SoftwareSerial (RX, TX) for Bluetooth

void setup()
{
  LeftServo.attach(leftServoPin);
  RightServo.attach(rightServoPin);
  Serial.begin(9600);
  mySerial.begin(9600);         //Set Bluetooth Baud rate
  pinMode(ledPin, OUTPUT);      //LED
  pinMode(buzzerPin, OUTPUT);           //Buzzer

} //End of function setup()




void loop()
{

  CheckLights(); //check if LED needs to be turn on
  SetBotSpeed(); //check Potentiometer for speed values

  if (mySerial.available() > 0) {
    prevInput = input;
    input = mySerial.read();
  }


  // If it receives '1' on the serial port, go forward
  if (input == 1) {
    MoveForward();
  }
  // If it receives '2' on the serial port, go backwards
  else if (input == 2) {
    MoveBackward();
  }
  // If it receives '3' on the serial port, rotate left
  else if (input == 3) {
    TurnLeft();
  }
  // If it receives '4' on the serial port, rotate right
  else if (input == 4) {
    TurnRight();
  }
  // If it receives '5' on the serial port, stop both servos
  else if (input == 5) {
    StopRobot();
  }
  // If it receives '6' on the serial port, set off buzzer
  else if (input == 6) {
    Honk();
  }
  //delay(50);
} //End of Function loop()


// Driving Functions **************


// A function created to check if its dark outside and turn lights on
void CheckLights() {
  int photoSensorReading = analogRead(A1); //PhotoResistor
  //Check if lights needs to be if as its dark outside

  if (photoSensorReading <= 250) {
    digitalWrite(ledPin, HIGH); //turn LED on
  }
  else {
    digitalWrite(ledPin, LOW); //turn LED off
  }
} //End of Function

// A function created to get speed thresholds from potentiometer
// returns speed value represented as int
// Fast = 1
// Medium = 2
// Slow = 3
void SetBotSpeed() {
  int potentioMeterReading = analogRead(A3); //Potentiometer
  Serial.println(potentioMeterReading);
  if (potentioMeterReading > 682) {
    speed = 1;
  } else if (potentioMeterReading <= 682 && potentioMeterReading > 341) {
    speed = 2;
  } else {
    speed = 3;
  }
  //Serial.println(speed);
} //End of Function

//A function created to STOP the bot
void StopRobot() {
  LeftServo.writeMicroseconds(1500);
  RightServo.writeMicroseconds(1500);
} //End of Function

//A function created to turn Left
void TurnLeft() {
  LeftServo.write(0);
  RightServo.write(0);
  delay(100);
  input = prevInput;
} //End of Function

//A function created to turn Right
void TurnRight() {
  LeftServo.write(180);
  RightServo.write(180);
  delay(100);
  input = prevInput;
} //End of Function

//A function created to go Backwards
void MoveBackward() {
  if (speed == 1) {
    LeftServo.writeMicroseconds(1600);
    RightServo.writeMicroseconds(1400);
  } else if (speed == 2) {
    LeftServo.writeMicroseconds(1550);
    RightServo.writeMicroseconds(1450);
  } else {
    LeftServo.writeMicroseconds(1525);
    RightServo.writeMicroseconds(1475);

  }
} //End of Function

//A function created to go Forward
void MoveForward() {

  if (speed == 1) {
    LeftServo.writeMicroseconds(1400);
    RightServo.writeMicroseconds(1600);
  } else if (speed == 2) {
    LeftServo.writeMicroseconds(1450);
    RightServo.writeMicroseconds(1550);
  } else {
    LeftServo.writeMicroseconds(1475);
    RightServo.writeMicroseconds(1525);
  }

} //End of Function

//A function created to set off the buzzer to simulate a car honking
void Honk() {
  tone (buzzerPin, 1000); // Send 1KHz sound signal...
  delay(1000);            // play for 1 sec
  noTone(buzzerPin);      // stop buzzer
  input = 0;
} //End of Function
