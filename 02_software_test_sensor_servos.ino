#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name

void setup(){
  int distance = 100;

  servo_motor.attach(11); //our servo pin

  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  
  Serial.begin(9600);
  Serial.println("Preparado.");
}

void loop(){

  int distanceRight = lookRight();
  Serial.print("Mira a la derecha: ");
  Serial.print(distanceRight);
  Serial.println(" cm.");
  delay(2000);
  int distance = readPing();
  Serial.print("frente: ");
  Serial.print(distance);
  Serial.println(" cm.");
  delay(2000);
  int distanceLeft = lookLeft();
  Serial.print("Mira a la izquierda: ");
  Serial.print(distanceLeft);
  Serial.println(" cm.");
  delay(2000);
}

int lookRight(){  
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}
