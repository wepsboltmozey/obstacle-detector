
#include<Servo.h>
//#define echo 2 // attach pin D2 Arduino to pin Echo of HC-SR04
//#define trigPin 3  // attach D3 Arduino to pin Trig of HC-SR04

// define variables

Servo myServo;
int right = 0;
int left = 0;
int duration;
int trig = 7;
int echo = 5;
int IN1 = 11;
int IN2 = 10;
int IN3 = 9;
int IN4 = 6;
int pos = 0;
int stopdistance = 10;




void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  myServo.attach(4);
  
}
 int getDistance(){
  int distance;
  digitalWrite(trig,HIGH);
  delay(2);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration*0.034 )/2;
  return distance;
  }
//checking distance
void Checkdir(){
  int turndirection =1;
  myServo.write(180);
  delay(100);
  right = getDistance();
  myServo.write(0);
  delay(100);
  left = getDistance();

  if(right > left){
    Serial.println(right);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, LOW);
    delay(1000);
    Foward();
    }
  else{
    Serial.println(left);
    digitalWrite(IN1, LOW);
    digitalWrite(IN3, HIGH);
    delay(1000);
    Foward();
    }
      
  }
  
  void Foward(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, HIGH);
    }

  void Backward(){
    digitalWrite(IN2, HIGH);
    digitalWrite(IN4, HIGH);
    }

   void Stop(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    }

void loop() {
  // put your main code here, to run repeatedly:
  
  myServo.write(90);
  delay(500);
  
  while(getDistance() > stopdistance){
    Foward();
    delay(20);
    
    }
    if(getDistance() <= stopdistance){
      Stop();
      delay(20);
      Checkdir();
    }
}
