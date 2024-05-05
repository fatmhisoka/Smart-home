#include <Servo.h>

Servo servo;

#define DO_PIN 2
float x,y;             //TEMP
#define trigPin 8    //ULTRA
#define  echoPin 9
// int ledPin= 13;  
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(11);
  servo.write(0);
  pinMode(DO_PIN, INPUT);
  pinMode(trigPin, OUTPUT); //12  PIN  ULTRA
  pinMode(echoPin, INPUT);  //10 PIN ULTRA
  // pinMode(ledPin, OUTPUT);  //13 PIN  ULTRA
  }

  


void loop() {
  

  x=analogRead(0);                 //TEMP
  y=((x/1024)*5)*100;
  Serial.println(y);
  delay(500);
  
  // digitalWrite(trigPin, HIGH);           //ULTRA
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // duration = pulseIn(echoPin, HIGH);
  // distance  = (duration / 2) / 29.1;

  // if (distance >= 10 || distance <= 0) 
  // {
  // // Serial.println("no object detected");

  // // digitalWrite(ledPin,LOW);
  // }
  // else 
  // {
  // Serial.print("distance=  ");
  // Serial.print(distance);       
  // // digitalWrite(ledPin,HIGH);
  // }     

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance from the object = ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 10)
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
  }else{
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
  }


  // put your main code here, to run repeatedly:
  int lightState = digitalRead(DO_PIN);

  if (lightState == HIGH){
    Serial.println("The light is NOT present");
    servo.write(90);
  } 
  else{
    Serial.println("The light is present");
    servo.write(0);
  }

  if(digitalRead(10)==HIGH)                  //pir
 {
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);

  Serial.println("object detected");
  delay(500);
 }
  else  { 
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);

   Serial.println("object not detected");
   }
  delay(1000);
     
}