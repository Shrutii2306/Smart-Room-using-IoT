#include <Servo.h>
	const int topLdrPin = A0;      // Analog pin connected to top LDR
	const int bottomLdrPin = A1;   // Analog pin connected to bottom LDR
	const int servoPin = 9;        // Digital pin connected to servo motor
	Servo myservo;  // Create a servo object
void setup() {
  	myservo.attach(servoPin);   // Attaches the servo on pin 9 to the servo object
  	Serial.begin(9600);         // Initialize serial communication at 9600 bps
}
void loop() {
  	  	 int topSensorValue = analogRead(topLdrPin);       // Read the value from the top LDR
 		   int bottomSensorValue = analogRead(bottomLdrPin); // Read the value from the bottom LDR
  		// Map the sensor values to servo angle range
  	 	  int servoAngle = map(bottomSensorValue - topSensorValue, -1023, 1023, 0, 180);
  	 	  myservo.write(servoAngle);  // Set the servo position based on the sensor values
     			delay(1000);                  // Delay for smooth movement
  		 	 Serial.print("Top LDR Value: ");
  		 	 Serial.println(topSensorValue);     // Print the top LDR value to the serial monitor
  		 	 Serial.print("Bottom LDR Value: ");
  			Serial.println(bottomSensorValue);  // Print the bottom LDR value to the serial monitor
}
