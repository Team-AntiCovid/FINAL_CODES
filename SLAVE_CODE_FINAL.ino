#include<Wire.h>

int trigPin1=A3;
int trigPin2=6;
int trigPin3=10;
int echoPin1=A4;
int echoPin2=5;
int echoPin3=9;
int buzzer=A1;


int sensor_slave=0;



void setup() {
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT);
  pinMode(A0,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(A0,LOW);
  digitalWrite(A5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(8,LOW);
  digitalWrite(A2,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(11,HIGH);

  Serial.begin(9600);
  
 
 
}
void loop() {
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  long duration1 = pulseIn(echoPin1, HIGH);
  int distance1 = duration1 * 0.0348 / 2; 
  Serial.print(distance1);
  Serial.print(" ");
  
  

  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 * 0.0348 / 2; 
  Serial.print(distance2);
  Serial.print(" ");
 


   
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  long duration3 = pulseIn(echoPin3, HIGH);
  int distance3 = duration3 * 0.0348 / 2; 
  Serial.print(distance3);
  Serial.println(" ");



  if(( distance1<80)||( distance2<80)||( distance3<80))
  {tone(buzzer,2500,50);          
      delay(100); }
                     
  else
  digitalWrite(buzzer,LOW);


  
 

  
}
