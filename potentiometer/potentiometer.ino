void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  int sensorReading2 = analogRead(A3);
  //Serial.println(sensorReading2);
  int speed1 = 0;
  int speed2 = 0;
  
  if (sensorReading2 > 600) 
  {
    int speed1 = 100;
    int speed2 = 200;
    Serial.println(speed1);
    Serial.println(speed2);
  } 
  else if (sensorReading2 < 600)
  {
    int speed1 = 1;
    int speed2 = 2;
    Serial.println(speed1);
    Serial.println(speed2);
  }
  else 
  {
  }
}
