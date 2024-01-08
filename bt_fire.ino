#include <Wire.h>
#include <LiquidCrystal_I2C.h>
char Incoming_value = 0;
const int motorPin = 2;
// const int flamepin=A2;
// const int buzpin=7;
// const int threshold=200;// sets threshold value for flame sensor
// int flamesensvalue=0; // initialize flamesensor reading
int led1 = 11;   
int led2 = 12;
int lcd1 = A5;
int lcd2 = A4;
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() 
{
   
  Serial.begin(9600);         
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  //pinMode(led3, OUTPUT);
  // pinMode(led4, OUTPUT);
  // pinMode(led5, OUTPUT);
  lcd.noDisplay();
  lcd.noBacklight();
  pinMode(lcd1, OUTPUT);
  pinMode(lcd2, OUTPUT);
  pinMode(motorPin, OUTPUT);  
  //pinMode(flamepin,INPUT);
  //pinMode(buzpin,OUTPUT); 
     
}

void loop()
{

  pinMode(lcd1, LOW);
  pinMode(lcd2,LOW);
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");       

    if(Incoming_value == 'a')             
    {  digitalWrite(led1, HIGH); 
      digitalWrite(led2, HIGH);
      Serial.print("\nled 2 on");
     }
    else if(Incoming_value =='b')       
    {  digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      Serial.print("\nled 2 off");
    }

    else if(Incoming_value == 'c')       
    {  
      // digitalWrite(motorPin, HIGH);
      // Serial.print("\nfan on");
      digitalWrite(lcd1, HIGH);
      digitalWrite(lcd2,HIGH);
      
      lcd.begin();         // initialize the lcd
      lcd.backlight(); 
      lcd.setCursor(1, 0);
      lcd.print("Hello World.!");
      delay(3000);
      lcd.clear();

      lcd.setCursor(2, 0);
      lcd.print("This is a LCD ");
      lcd.setCursor(2, 1);
      lcd.print("Screen Test");
      delay(3000);
      lcd.clear();
      
    }
    else if(Incoming_value == 'd')       
    {  
      lcd.noBacklight();
      lcd.noDisplay();
      digitalWrite(lcd1, LOW);
      digitalWrite(lcd2, LOW);
      digitalWrite(motorPin, LOW);
      Serial.print("\nfan off");
    }
    
  }                            
} 