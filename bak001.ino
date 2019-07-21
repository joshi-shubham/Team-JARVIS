#include <Wire.h>
int count;
int count2;
const int trigPin1 = 11;
const int echoPin1 = 12;
const int trigPin2 = 9;
const int echoPin2 = 13;
const int buzzPin =8;
long duration;
int distanceCm;
int distanceCm2;
void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}
void loop() {
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration = pulseIn(echoPin1, HIGH);
  distanceCm = duration * 0.0340 / 2;
  Serial.println(distanceCm);
  if(distanceCm == 0 || distanceCm >120){
    distanceCm = 0;  
    digitalWrite(buzzPin, LOW); 
  }else if (distanceCm <= 60){
    digitalWrite(buzzPin, HIGH);
    delay(10);
    digitalWrite(buzzPin, LOW);
    delay(10);
    digitalWrite(buzzPin, HIGH);
    delay(10);
    digitalWrite(buzzPin, LOW);
  }else{
    digitalWrite(buzzPin, HIGH);
  }




  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  duration = pulseIn(echoPin2, HIGH);
  distanceCm2 = duration * 0.0340 / 2;
  Serial.println(distanceCm2);
  if(distanceCm2 == 0 || distanceCm2 >400){
    distanceCm2 = 0;
    count++;
    if(count>2){
    for(int i=0;i<5;i++){
       count =0;
       count2=0;
       digitalWrite(buzzPin, HIGH);
       delay(20);
       digitalWrite(trigPin2, LOW);
       //delay(10);
      }
    }
   
  }else{
  count2++;
  if(count2>5){
    count2=0;
    count =0;
    }
    digitalWrite(buzzPin, LOW);
  }
}
