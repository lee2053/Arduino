#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 494
#define NOTE_HC 515

const int SPEAKER=10;
const int BUTTON_C=2;
const int BUTTON_D=3;
const int BUTTON_E=4;
const int BUTTON_F=5;
const int BUTTON_G=6;
const int BUTTON_A=7;
const int BUTTON_B=8;
const int BUTTON_HC=9;

#include<Servo.h>                //Adding the Servo library

Servo myservo;            //Define an object named MyServo
const int eko=12;        
const int trig=13;        
int mesafe;
int sure;


void setup(){
  myservo.attach(11);           //We introduced the thirtin pin arduino to the servo motor
  pinMode(trig,OUTPUT);        
  pinMode(eko,INPUT);    
}

void loop()
{
  while(digitalRead(BUTTON_C))
        tone(SPEAKER, NOTE_C);     
  while(digitalRead(BUTTON_D))
        tone(SPEAKER, NOTE_D);
  while(digitalRead(BUTTON_E))
        tone(SPEAKER, NOTE_E);
  while(digitalRead(BUTTON_F))
        tone(SPEAKER, NOTE_F);
  while(digitalRead(BUTTON_G))
        tone(SPEAKER, NOTE_G);
  while(digitalRead(BUTTON_A))
        tone(SPEAKER, NOTE_A);
  while(digitalRead(BUTTON_B))
        tone(SPEAKER, NOTE_B);
  while(digitalRead(BUTTON_HC))
        tone(SPEAKER, NOTE_HC);

        
  noTone(SPEAKER);
   myservo.write(0);       
  Serial.begin(9600);     
  
 
   
  digitalWrite(trig, LOW);         
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);       
  delayMicroseconds(20);
  digitalWrite(trig, LOW);         
  sure = pulseIn(eko, HIGH);      
  mesafe= (sure/29.1)/2;  
  

  if(mesafe<=5){
    myservo.write(160);
    delay(5000);   
  }
  
   
  if(mesafe>200)
mesafe=200;
Serial.print("mesafe");
Serial.println(mesafe);
delay(500); 
}
