#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN 5
#define ECHO_PIN 6
#define MAX_DISTANCE 40
int kondisiServo=0;


Servo myservo;
// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
 
void setup() {
   myservo.attach(3);
   Serial.begin(9600);
   Serial.println("Start");
}
 
void loop() {
   delay(50);
   unsigned int distance = sonar.ping_cm();
   Serial.print(distance);
   Serial.print(" cm ");
   Serial.println(kondisiServo);

   if (distance>=2 && distance <=16){
    myservo.write(35);
    delay(10);
    myservo.write(75);
    delay(500);
    myservo.write(35);
    delay(1500);
    kondisiServo=1;
    Serial.print(distance);
    Serial.print(" cm ");
    Serial.println(kondisiServo);
   }
    if (distance<16 || distance ==0){
    myservo.write(35);
    delay(500);
    kondisiServo=0;
    Serial.print(distance);
    Serial.print(" cm ");
    Serial.println(kondisiServo);
   }
}
