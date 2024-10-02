void setup() {
    Serial.begin(9600);
}

void loop() {
  int rawVoltage = analogRead(A0);
  
  //float voltage = rawValue * (5.0 / 1023.0);
  //Serial.print(voltage);
  //Serial.println(" Volts");

  float temp = rawVoltage * (5.0 / 1023.0) * 2 + 18;

  Serial.print(temp);
  Serial.println(" grader");

  delay(100);
}
