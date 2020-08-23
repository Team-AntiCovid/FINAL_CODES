int trigPin0=2;
int trigPin1=A3;
int trigPin2=6;
int trigPin3=10;             // TRIGGER PINS ASSIGNED

int echoPin0=1;
int echoPin1=A4;
int echoPin2=5;
int echoPin3=9;              // ECHO PINS ASSIGNED

int buzzer=A1;               // POSITIVE TERMINAL OF BUZZER ASSIGNED




void setup() {
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT);
  pinMode(A0,OUTPUT);
  pinMode(buzzer,OUTPUT);                // TRIGGER PINS,ECHO PINS AND BUZZER PINS SET AS INPUT AND OUTPUT
  
  pinMode(0,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);                    // VCC AND GND PINS SET AS OUTPUT


  digitalWrite(0,LOW);
  digitalWrite(A0,LOW);
  digitalWrite(A5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(8,LOW);                    // GND PINS SET AS LOW

  digitalWrite(3,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(11,HIGH);                  // VCC PINS SET AS HIGH 
  

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
  Serial.print(" ");                         // GETTING DISTANCE FROM SENSOR1
  
  

  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 * 0.0348 / 2; 
  Serial.print(distance2);
  Serial.print(" ");                              // GETTING DISTANCE FROM SENSOR2
 


   
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  long duration3 = pulseIn(echoPin3, HIGH);
  int distance3 = duration3 * 0.0348 / 2; 
  Serial.print(distance3);
  Serial.println(" ");                             // GETTING DISTANCE FROM SENSOR3


     
  digitalWrite(trigPin0, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin0, LOW);
  long duration0 = pulseIn(echoPin0, HIGH);
  int distance0 = duration0 * 0.0348 / 2; 
  Serial.print(distance0);
  Serial.println(" ");                             // GETTING DISTANCE FROM SENSOR3



  if((distance0>30 && distance0<60)||(distance1>30 && distance1<80)||( distance1>30 && distance2<80)||( distance1>30 && distance3<80))// DISTANCE>30 SO THAT OUR HANDS ARE NOT DETECTED
                                                                                                       // DISTANCE OF DETECTION CAN BE INCREASED MORE IF REQUIRED
  {tone(buzzer,2500,50);          
      delay(100); }
                     
  else
  digitalWrite(buzzer,LOW);


  
 

  
}
