char Incoming_value = 0;
 const int motorPin = 2;
const int flamepin=A2;
const int buzpin=7;
const int threshold=200;// sets threshold value for flame sensor
int flamesensvalue=0; // initialize flamesensor reading
int led1 = 13;   
int led2 = 12; 
int led3 = 11;
int led4 = 10;
int led5 = 9;            
void setup() 
{
  Serial.begin(9600);         
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(motorPin, OUTPUT);  
  pinMode(flamepin,INPUT);
  pinMode(buzpin,OUTPUT);     
}

void loop()
{

  flamesensvalue=analogRead(flamepin); // reads analog data from flame sensor
  if (flamesensvalue<=threshold) { // compares reading from flame sensor with the threshold value
  //turns on buzzer
  tone(buzpin,100);
  }
  else{
  //turns off buzzer
  noTone(buzpin);
  }

  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");       
  
    if(Incoming_value == 'a')             
    {  
      digitalWrite(led1, HIGH); 
      Serial.print("\nled 1 on");
      
    } 
    else if(Incoming_value == 'b')       
    {  
      digitalWrite(led1, LOW);
      Serial.print("\nled 1 off");
    }

    else if(Incoming_value == 'c')             
    {  
      digitalWrite(led2, HIGH);
      Serial.print("\nled 2 on");
     }
    else if(Incoming_value =='d')       
    {  
      digitalWrite(led2, LOW);
      Serial.print("\nled 2 off");
    }

    else if(Incoming_value == 'e')             
    {  
      digitalWrite(led3, HIGH);
      Serial.print("\nled 3 on");
    }  
    else if(Incoming_value =='f' )       
    {
      digitalWrite(led3, LOW);
      Serial.print("\nled 3 off");
    }
    else if(Incoming_value == 'g')             
    {  
      digitalWrite(led4, HIGH);
      Serial.print("\nled 4 on"); 
    } 
    else if(Incoming_value == 'h')       
    {  
      digitalWrite(led4, LOW);
      Serial.print("\nled 4 off");
      
    }

    else if(Incoming_value == 'i')             
    {  
      digitalWrite(led5, HIGH);
      Serial.print("\nled 5 on"); 
      
    } 
    else if(Incoming_value == 'j')       
    {   
      digitalWrite(led5, LOW);
      Serial.print("\nled 5 off");
    }
  

  else if(Incoming_value == 'k')       
    {  
      digitalWrite(motorPin, HIGH);
      Serial.print("\nfan on");
      
    }
    else if(Incoming_value == 'l')       
    {  
      digitalWrite(motorPin, LOW);
      Serial.print("\nfan off");
    }
    /*
    else if(Incoming_value == 'm')       
      digitalWrite(motorPin, HIGH);
    else if(Incoming_value == 'n')       
      digitalWrite(motorPin, LOW);*/
    
  }                            
} 