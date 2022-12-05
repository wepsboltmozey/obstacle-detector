#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3  // attach D3 Arduino to pin Trig of HC-SR04

// define variables
long distance;
int Distance;
int duration;
int relay = 5;
int Buzzer = 7;
int Red = 8;
int Blue = 9;
int Green = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Sets the trigPin High (Active) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);

  //Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  //Calculating the distance 
  distance = duration * 0.034 / 2;  //Speed of sound wave divided by 2
  //return distance;

  //Displays the distance on the Serial Monitor
  //Serial.print(" cm");
  Serial.print("Distance: ");
  Serial.println(distance );
  delayMicroseconds(20);
  
  //return 0;
  if(distance <=20){
    digitalWrite(relay, LOW);
    digitalWrite(Buzzer, HIGH);
    delay(100);
    noTone(Buzzer);
    delay(100);
    
    digitalWrite(Red, LOW);
    digitalWrite(Green, LOW);
    digitalWrite(Blue, HIGH);
    delay(10);
    
    }
  else{
    digitalWrite(relay, HIGH);
    digitalWrite(Buzzer, LOW);
    digitalWrite(Red, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Green, LOW);
    }

   if(distance >20 && distance >=40){
    digitalWrite(relay, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Green, LOW);
    digitalWrite(Red, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(50);
    noTone(Buzzer);
    delay(50);
    }
  else{
    digitalWrite(relay, HIGH);
    digitalWrite(Buzzer, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Red, LOW);
    digitalWrite(Green, LOW);
    }

    if(distance >40 && distance >=80){
    digitalWrite(relay, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Green, HIGH);
    digitalWrite(Red, LOW);
    digitalWrite(Buzzer, HIGH);
    delay(100);
    noTone(Buzzer);
    delay(100);
    }
  else{
    digitalWrite(relay, HIGH);
    digitalWrite(Buzzer, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Red, LOW);
    digitalWrite(Green, LOW);
    }
     
}
