https://bisregistrations.lntedutech.com/bis-registration/?wpforms_resume_entry=8pn6mkykZtDjnu7/cBOqtveGQ3nrRA6/Ycmg4OVy0iNM+ue3JOz/L3GZ/gnY



#define trigPin 5
#define echoPin 4
int ldr = A0;
int Watersensor = 3;
int Buzzer = 9;
int RF = 8;
int brightness = 0;    
int fadeAmount = 5; 
 
void setup()
{
  Serial.begin(9600); // set your baud rate
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Watersensor,INPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(RF,INPUT);
}
void loop()
{
  Serial.print(ultrasonic());
int WS=digitalRead(Watersensor);
int missingalarm=digitalRead(RF);
  if(LDR() < 200)
  {
    digitalWrite(Buzzer,HIGH);
    delay(300);
    digitalWrite(Buzzer,LOW);
    delay(100);
  }
 else if(WS == HIGH)
 {
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    delay(30);
  }
 else if(missingalarm == HIGH)
  {
    analogWrite(Buzzer, brightness);    
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) 
      {
        fadeAmount = -fadeAmount ; 
      }     
      delay(30);      
 }
    else if(ultrasonic() < 10)
  {
    digitalWrite(Buzzer,HIGH);
    //delay(1000);
  }
  else if (missingalarm == LOW || ultrasonic() > 10 || WS == LOW || LDR() > 200)
  { 
    digitalWrite(Buzzer,LOW);
  }
}  
int LDR()
{
  int LDR=analogRead(ldr);
  return LDR;
}  
int ultrasonic()
{
long duration, distance;
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
delay(30);
return distance;
}
