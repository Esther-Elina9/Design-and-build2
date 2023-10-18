// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"
#include<Servo.h>
Servo duoji1;
Servo duoji2;
// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN2 50
#define ECHO_PIN2 52
#define TRIGGER_PIN1 4
#define ECHO_PIN1 5

#define TRIGGER_PIN3 43
#define ECHO_PIN3 41
#define TRIGGER_PIN4 12
#define ECHO_PIN4 13
// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400    
// Motor A connections
int in1 = 30;
int in2 = 32;
// Motor B connections
int in3 = 34;
int in4 = 36;

// NewPing setup of pins and maximum distance.
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);
NewPing sonar4(TRIGGER_PIN4, ECHO_PIN4, MAX_DISTANCE);
float duration, dis1, dis2, dis3, dis4;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 	// Set all the motor control pins to outputs
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  duoji1.attach(10);
  duoji2.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
Dect();
if(dis1!=0&&dis2!=0&&dis3!=0){
if(dis1<22){
  if(dis2+dis3>30){
    if(dis2>dis3){
      Left();
    }
    if(dis3>=dis2){
      Right();
    }
  }
  if(dis3>10&&dis2<10){
    Right();
    Backward();
  }
  if(dis2>10&&dis3<10){
    Left();
    Backward();
  }
  if(dis3+dis2<20){
    if(dis4-dis1>5 && dis4+dis1<30){
      Stop();
      
      for(int i=0;i<150;i++)
      {
        duoji1.write(i);
        delay(10);
      }
      for(int i=70;i<150;i++)
      {
        duoji2.write(i);
        delay(10);
      }
      for(int i=149;i>=70;i--)
      {
   
        duoji2.write(i);
        delay(10);
      }
      for(int i=150;i<300;i++)
      {
        duoji1.write(i);
        delay(10);
      }
      for(int i=70;i<150;i++)
      {
        duoji2.write(i);
        delay(10);
      }
      for(int i=149;i>=70;i--)
      {
        duoji2.write(i);
        delay(10);
      }
      for(int i=299;i>=0;i--)
      {
        duoji1.write(i);
        delay(10);
      }
    }
    Backward();
    Left();
    Backward();
    Left();
  }
}else{
  Forward();
  if(dis2<5){
      Right1();
    }
  if(dis3<5){
      Left1();
    }
}
}

}
// This function lets you control spinning direction of motors
void Right() {
	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  delay(350);
}
void Right1() {
	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  delay(100);
}
void Left(){
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  delay(350);
}
void Left1(){
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  delay(100);
}

void Backward(){
	// Now change motor directions
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  delay(10);
}

void Forward(){
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  delay(700);
}



void Stop(){
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  delay(10);
}
void Dect(){
    dis1 = sonar1.ping_cm();
    dis2 = sonar2.ping_cm();
    dis3 = sonar3.ping_cm();
    dis4 = sonar4.ping_cm();
    // Send results to Serial Monitor
    Serial.print("Dis1 = ");
    Serial.print(dis1);
    Serial.print("Dis2 = ");
    Serial.print(dis2);
    Serial.print("Dis3 = ");
    Serial.print(dis3);
    Serial.print("Dis4 = ");
    Serial.print(dis4);  
    Serial.println(" cm");
}

