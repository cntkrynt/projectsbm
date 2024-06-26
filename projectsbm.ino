#include <Servo.h>

Servo myservo;  // definisi servo untuk dioperasikan
float temp; // definisi temp sebagai variabel float
float vout; //definisi vout sebagai variabel float
float vout1; // definisi vout1 sebagai variabel float 
float gasSensor; // definisi gasSensor sebagai variabel integer
int poson = 1;   // posisi on servo
int posoff = 100;  // posisi off servo
int pirPin = 7;    // digital sensor pin di 7
int ledPin = 13; // digital sensor pin di 13
int led2Pin= 12; // digital sensor pin di 12
int piezo = 4; // digital sensor pin di 4
 
void setup() {
  pinMode(pirPin,INPUT); // setup sensor pin sebagai input
  pinMode(ledPin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  digitalWrite(pirPin, LOW);
  myservo.attach(9);  // digital pin servo  di pin pwm 9 
  //delay(30000); // kalibrasi sensor
  pinMode(A0,INPUT); 
  pinMode(A1,INPUT);  
  pinMode(piezo,OUTPUT); }

void loop() {
  vout=analogRead(A1); 
  vout1=(vout/1023)*5000; 
  temp=(vout1-500)/10; 
  gasSensor=analogRead(A0);

 if(digitalRead(pirPin)==HIGH) { 
    digitalWrite(ledPin,HIGH);
    digitalWrite(led2Pin,LOW);
    myservo.write(45);              // servo berada saat posisi poson 
    delay(5000);    
    myservo.write(90);              // server berada saat posisi posoff
    digitalWrite(ledPin,LOW);
    digitalWrite(led2Pin,HIGH);
    delay(1000);   //delay 
    digitalWrite(led2Pin,LOW); }
  
  else if (temp>=80 || gasSensor>=100){ //sensor kebakaran di pintu otomatis
     myservo.write(45);
     digitalWrite(piezo,HIGH);
     digitalWrite(ledPin, LOW);
     digitalWrite(led2Pin, HIGH);
     delay(1000);}  
  else {
     digitalWrite(piezo,LOW);
     digitalWrite(ledPin, LOW);
     digitalWrite(led2Pin, LOW);}
}