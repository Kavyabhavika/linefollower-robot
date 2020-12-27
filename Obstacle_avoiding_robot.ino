
int LM1 = 7; // left motor 1
int LM2 = 8; // left motor 2
int PWM1 = 9;  //PWM for LM

int PWM2 = 10; // PWM for RM
int RM1 = 11; // right motor 1
int RM2 = 12; // right motor 2

int TP1 = A0; //trigpin 1
int EP1 = A1; //echopin 1
int duration1;
int distance1;

int TP2 = A2; //trigpin 2
int EP2 = A3; //echopin 2
int duration2;
int distance2;

int TP3 = A4; //trigpin 3
int EP3 = A5; //echopin3
int duration3;
int distance3;

void setup() {
  // put your setup code here, to run once
 
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  
  pinMode(RM1,OUTPUT); 
  pinMode(RM2,OUTPUT);
  
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  
  pinMode(TP1,OUTPUT);
  pinMode(EP1,INPUT);
  
  pinMode(TP2,OUTPUT);
  pinMode(EP2,INPUT);
  
  pinMode(TP3,OUTPUT);
  pinMode(EP3,INPUT);

  analogWrite(PWM1,80);
  analogWrite(PWM2,80);
 
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly

  digitalWrite(TP1, LOW);
  delayMicroseconds(2);
  digitalWrite(TP1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP1, LOW);
  duration1 = pulseIn(EP1, HIGH);
  distance1= duration1*0.034/2;

   digitalWrite(TP2, LOW);
  delayMicroseconds(2);
  digitalWrite(TP2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP2, LOW);
  duration2 = pulseIn(EP2, HIGH);
  distance2= duration2*0.034/2;

   digitalWrite(TP3, LOW);
  delayMicroseconds(2);
  digitalWrite(TP3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP3, LOW);
  duration3 = pulseIn(EP3, HIGH);
  distance3= duration3*0.034/2;

  Serial.print("front = ");
  Serial.println(distance1);
  Serial.print("Left = ");
  Serial.println(distance2);
  Serial.print("Right = ");
  Serial.println(distance3);  
  delay(50);

   if (distance1 >20){

    forward();
    
    if(distance2 > 10&& distance2<20){
      forward();
    }
    if(distance2 >=20){
       left();
       delay(30);
       forward();
    }
    if(distance2<10 && distance2>0){
      right();
      delay(30);
      forward();
    }
 } 
  
  if(distance1<=20&& distance3 > 20){
    Stop();
    delay(1000);
    right();
    delay(400);
    
  }

  if(distance1<=20 && distance3<20){
    Stop();
    delay(1000);
    right();
    delay(800);
   
  }
}


void forward()
{
   digitalWrite(LM1,HIGH); //forward
  digitalWrite(LM2,LOW);  
  digitalWrite(RM1,HIGH);  
  digitalWrite(RM2,LOW); 
  delay(100);
}


void right(){
  digitalWrite(LM1,LOW); //right
  digitalWrite(LM2,LOW);  
  digitalWrite(RM1,HIGH);  
  digitalWrite(RM2,LOW); 
 delay(100);
}


void left(){
  digitalWrite(LM1,HIGH); //left
  digitalWrite(LM2,LOW);  
  digitalWrite(RM1,LOW);  
  digitalWrite(RM2,LOW); 
  delay(100);
}



void Stop(){
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
  delay(100);
}
