
int LS = 1; //left sensor
int RS = 2; //right sensor
int LM1 = 7; // left motor 1
int LM2 = 8; // left motor 2
int PWM1 = 9;  //PWM for LM
int PWM2 = 10; // PWM for RM
int RM1 = 11; // right motor 1
int RM2 = 12; // right motor 2
int trigPin = 3; //trigpin
int echoPin = 4; //echopin
int buzzer =5; //buzzer
int duration;
int distance;


void setup() {
  // put your setup code here, to run once
 
   pinMode(LS,INPUT);
  pinMode(RS,INPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT); 
  pinMode(RM2,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzer,OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  
  delay(10);

  
   if (distance < 10) {
    digitalWrite(buzzer, HIGH);
    
  }
  else {
    digitalWrite(buzzer, LOW);
   
  }
if((digitalRead(LS)==0) && (digitalRead(RS) == 0))
{
  digitalWrite(LM1,HIGH); //forward
  digitalWrite(LM2,LOW);  
  digitalWrite(RM1,HIGH);  
  digitalWrite(RM2,LOW); 

  analogWrite (PWM1,100);
  analogWrite (PWM2,100);

   delay(10);
}
if((digitalRead(LS)==1) && (digitalRead(RS) == 0))
{
  digitalWrite(LM1,HIGH); //left
  digitalWrite(LM2,LOW);  
  digitalWrite(RM1,LOW);  
  digitalWrite(RM2,LOW); 
 

  analogWrite (PWM1,100);
  analogWrite (PWM2,100);

   delay(10);
}
if((digitalRead(LS) ==0) && (digitalRead(RS) == 1))
{
  digitalWrite(LM1,LOW); //right
  digitalWrite(LM2,LOW);  
  digitalWrite(RM1,HIGH);  
  digitalWrite(RM2,LOW); 


  analogWrite (PWM1,100);
  analogWrite (PWM2,100);

   delay(10);
}
if((digitalRead(LS) ==0) && (digitalRead(RS) == 0))
{
  analogWrite (PWM1,0); //stop
  analogWrite (PWM2,0);
}
}
 

 
  















  
