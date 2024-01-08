const int pirPin = 8;
const int motorPin = 2;
int state = LOW;
int led1 = 13; 
int led2 = 12;
//int led3 = 11;
//int led4 = 10;
//int led5 = 9;
const int flamepin=A2;
const int buzpin=7;
const int threshold=200;// sets threshold value for flame sensor
int flamesensvalue=0; // initialize flamesensor reading

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(motorPin, OUTPUT);
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);
  // pinMode(led3, OUTPUT);
  // pinMode(led4, OUTPUT);
  // pinMode(led5, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(flamepin,INPUT);
  pinMode(buzpin,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  int sensorValue;
  
  sensorValue = digitalRead(pirPin);
  flamesensvalue=analogRead(flamepin); // reads analog data from flame sensor

  if (flamesensvalue<=threshold) { // compares reading from flame sensor with the threshold value
   //turns on  buzzer
  tone(buzpin,200);
  }
  else{
  //turns led off buzzer
  noTone(buzpin);
  }

  if(sensorValue == HIGH)
  {  
    digitalWrite(motorPin, HIGH); // turn the motor on (full speed)
    digitalWrite(led1, HIGH);   // turn LED1 ON
    digitalWrite(led2, HIGH);   // turn LED2 ON
    // digitalWrite(led3, HIGH);   // turn LED3 ON
    // digitalWrite(led4, HIGH);   // turn LED4 ON
    // digitalWrite(led5, HIGH);   // turn LED5 ON
    delay(20);

     if (state == LOW) {
      Serial.print("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }

  } else {
    digitalWrite(led1, LOW); // turn LED1 OFF
    digitalWrite(led2, LOW); // turn LED2 OFF
    // digitalWrite(led3, LOW); // turn LED3 OFF
    // digitalWrite(led4, LOW); // turn LED4 OFF
    // digitalWrite(led5, LOW); // turn LED5 OFF
    digitalWrite(motorPin, LOW); // turn the motor off 
    delay(30); 
    if (state == HIGH){
        Serial.print("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}