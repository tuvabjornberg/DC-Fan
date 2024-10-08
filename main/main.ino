int redLed = 13;
int yellowLed = 12;
int greenLed = 11;
int fan = 5;

void setup() {
  Serial.begin(9600);
	pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(fan, OUTPUT); 
}

void loop() {
  //int rawVoltagePotent = analogRead(A0);
  int setpointVoltage = analogRead(A0);
  int rawVoltageTmpSensor = analogRead(A1);

  //digitalWrite(redLed, HIGH);
  //delay(1000);                     
  //digitalWrite(redLed, LOW);

  //digitalWrite(fan, HIGH);
  //delay(5000);
  //digitalWrite(fan, LOW);

  
  //float voltage = rawValue * (5.0 / 1023.0);
  float setTemp = setpointVoltage * (5.0 / 1023.0) * 2 + 18; //Degrees celsius, set through pot. meter

  float voltageOutTmpSensor = rawVoltageTmpSensor * (5.0 / 1023.0);
  float tempSensorNow = (voltageOutTmpSensor - 0.424)/ 0.00625; //OBS! Be wary of bottow view of temp sensor, function from tmp sensor datasheet



  float tempDiff = tempSensorNow-setTemp;
  Serial.print("Tempdiff: ");
  Serial.println(tempDiff);
  if (tempDiff > 0) {

    if (tempDiff > 5) { //Actual temp more than 5 degrees from set temp
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, LOW);

      analogWrite(fan, 255); //Run at full speed
    } else {
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(greenLed, LOW);

      analogWrite(fan, (255/5)*(tempDiff));
    }
    
    //digitalWrite(fan, HIGH);

  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);

    //digitalWrite(fan, LOW);
    analogWrite(fan, 0); //No speed
  }


  Serial.print(setTemp);
  Serial.println(" grader POTENTIOMETER");
  
  Serial.print(voltageOutTmpSensor);
  Serial.println(" volt TMP SENSOR");

  Serial.print(tempSensorNow);
  Serial.println(" grader nu!");

  delay(1000);
}
