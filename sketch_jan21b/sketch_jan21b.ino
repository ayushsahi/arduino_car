char receivedChar;
boolean newData = false;

void setup() {
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
}

void loop() {
 recvOneChar();
 showNewData();
}

void recvOneChar() {
 Serial.print("Direction is...  ");
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if ((receivedChar == "F") || (receivedChar == "B")) {
      newData = true;
    }
    else {
      newData = false;
    }
  }
}
void showNewData() {
  if (newData == true) {
    //Serial.println("Direction is...");
    Serial.println(receivedChar);
    newData = false;
 }
 else {
    digitalWrite(3, LOW);
  }
}
