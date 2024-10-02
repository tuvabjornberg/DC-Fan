void setup() {
    Serial.begin(9600);
}

void loop() {
  int rawVoltage = analogRead(A0);
  
  //float voltage = rawValue * (5.0 / 1023.0);
  //Serial.print(voltage);
  //Serial.println(" Volts");

  //float temp = rawVoltage * (5.0 / 1023.0) * 2 + 18;
  //Serial.print(temp);
  //Serial.println(" grader");

  float voltage = rawVoltage * (5.0 / 1023.0);
  float temp_sensor = (voltage - 0.424)/ 0.00625; //OBS! Be wary of bottow view of temp sensor
  
  Serial.print(voltage);
  Serial.println(" volt");
  
  Serial.print(temp_sensor);
  Serial.println(" grader nu!");

  delay(500);
}
