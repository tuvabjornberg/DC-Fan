int redLed = 4;
int yellowLed = 3;
int greenLed = 2;

void setup() {
  Serial.begin(9600);
	pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  //int rawVoltagePotent = analogRead(A0);
  int setpointVoltage = analogRead(A0);
  int rawVoltageTmpSensor = analogRead(A1);

  digitalWrite(redLed, HIGH);
  delay(1000);                     
  digitalWrite(redLed, LOW);
  
  //float voltage = rawValue * (5.0 / 1023.0);
  float setTemp = setpointVoltage * (5.0 / 1023.0) * 2 + 18; //Degrees celsius, set through pot. meter

  float voltageOutTmpSensor = rawVoltageSensor * (5.0 / 1023.0);
  float currentTempSensor = (voltageOutTmpSensor - 0.424)/ 0.00625; //OBS! Be wary of bottow view of temp sensor, function from tmp sensor datasheet
  
  Serial.print(voltageOutTmpSensor);
  Serial.println(" volt");

  Serial.print(currentTempSensor);
  Serial.println(" grader nu!");

  delay(500);
}
