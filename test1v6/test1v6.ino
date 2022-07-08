/* Beispielskizze zur Steuerung eines 28BYJ-48-Schrittmotors mit ULN2003-Treiberplatine, AccelStepper und Arduino UNO: Beschleunigung und Verzögerung. Mehr Infos: https://www.makerguides.com */

// AccelStepper-Bibliothek einbinden:
#include <AccelStepper.h>
//#include <Stepper.h>

// Definitionen der Motorpins:
#define MotorPin12 25 // IN1 auf dem ULN2003-Treiber
#define MotorPin22 26 // IN2 auf dem ULN2003-Treiber
#define MotorPin32 27 // IN3 auf dem ULN2003-Treiber
#define MotorPin42 14 // IN4 auf dem ULN2003-Treiber


#define MotorPin1 16 // IN1 auf dem ULN2003-Treiber
#define MotorPin2 17 // IN2 auf dem ULN2003-Treiber
#define MotorPin3 18 // IN3 auf dem ULN2003-Treiber
#define MotorPin4 19 // IN4 auf dem ULN2003-Treiber
// Schnittstellentyp AccelStepper definieren; 4-Draht-Motor im Halbschrittmodus:
#define MotorInterfaceType 8

// Initialisieren mit Pin-Sequenz IN1-IN3-IN2-IN4 für die Verwendung der AccelStepper-Bibliothek mit 28BYJ-48-Schrittmotor:
AccelStepper Stepper2 = AccelStepper (MotorInterfaceType, MotorPin1, MotorPin3, MotorPin2, MotorPin4);
AccelStepper Stepper3 = AccelStepper (MotorInterfaceType, MotorPin12, MotorPin32, MotorPin22, MotorPin42);
#define Switch1 22
#define Switch2 21
int a=0;
int b=0;
int c=0;
int x1;
int x2;
int x3;
int x4;
int x5;
int ay1;
int y2;
int y3;
int y4;
int y5;
int sendeInhalt ;
int yposition ;
char fifth= ' ';
char fth= ' ';
char trth= ' ';
char scth= ' ';
char frth= ' ';
char cy5= ' ';
char cy4= ' ';
char cy3= ' ';
char cy2= ' ';
char cy1= ' ';
void home(){
a=digitalRead(Switch1);
b=digitalRead(Switch2);
//while (Switch1==HIGH) {
  //Stepper2.move(-1);
  //delay (100);
  //digitalRead(Switch1); 
  // statement(s)
//}
 //Stepper2.setCurrentPosition(0);
while (b==1) {
  Stepper3.move(2000);
  Stepper3.run(); 
  b=digitalRead(Switch2);
  //delay (1000); 
  // statement(s)
}
 //Stepper2.setCurrentPosition(0);
while (b==0) {
  Stepper3.move(-1000);
  Stepper3.run(); 
  b=digitalRead(Switch2);
  //delay (1000); 
  // statement(s)
 }
while (b==1) {
Stepper3.setCurrentPosition(7500);
b=2;
  //delay (1000); 
  // statement(s)
}  
while (a==1) {
  Stepper2.move(2000);
  Stepper2.run(); 
  a=digitalRead(Switch1);
  //delay (1000); 
  // statement(s)
}
while (a==0) {
  Stepper2.move(-1000);
  Stepper2.run(); 
  a=digitalRead(Switch1);
  //delay (1000); 
  // statement(s)
}
while (a==1) {
Stepper2.setCurrentPosition(20000);
a=2;
  //delay (1000); 
  // statement(s)
}
sendeInhalt=20000;
yposition=7500;
c=9;
}

void setup() {
 Serial.begin(9600);
   // Legen Sie die maximalen Schritte pro Sekunde fest:
pinMode(Switch1, INPUT);
pinMode(Switch2, INPUT);
Stepper2.setMaxSpeed (800);
  // Setze die maximale Beschleunigung in Schritten pro Sekunde^2:
Stepper2.setAcceleration (1000);
Stepper3.setMaxSpeed (800);
  // Setze die maximale Beschleunigung in Schritten pro Sekunde^2:
Stepper3.setAcceleration (1000);
home();
}
void loop() {

if (c==9){

Serial.print("x position is");
Serial.println(sendeInhalt);
Serial.print("y position is");
Serial.println(yposition);


delay(3000);
c=0;}

if (c==0)
{Serial.println("set X Position");
delay(1000);
  Serial.println("set a 5 digit number betwin 0 and 15000 as XPosition");
c=4;}
{if (c==4)
  {if (Serial.available() > 0) //"wenn ein Datenpaket geliefert wird"
  {fifth = Serial.read(); //liest die Daten
  delay(100);
  fth = Serial.read(); 
    delay(100);
  trth = Serial.read(); 
    delay(100);
  scth = Serial.read(); 
    delay(100);
  frth = Serial.read(); 
    delay(100);
 int x5=fifth-'0';;
 int x4=fth-'0';;
 int x3=trth-'0';;
 int x2=scth-'0';;
 int x1=frth-'0';;
x5=x5 *10000;
x4=x4 *1000;
x3=x3 *100;
x2=x2 *10;
x1=x1 *1;
Serial.println(x5);
Serial.println(x4);
Serial.println(x3);
Serial.println(x2);
Serial.println(x1);
delay(1000);
Serial.flush(); //seriellen Puffer löschen
    c=1;
 Serial.println(x1);
 x1=x1+x2+x3+x4+x5;
 Serial.println(x1);
  sendeInhalt=(x1);
 if(x1<=15000){
  if (x1>=0){  
  Stepper2.moveTo(sendeInhalt);
  Stepper2.runToPosition();
  c=2;}}
  else {
  c=0;
  } 
  }}}
if (c==2)
{Serial.println("set y Position");
delay(1000);
  
  Serial.println("set a 4 digit number betwin 0 and 7500 as YPosition");
c=5;}
if (c==5);
  {if (Serial.available() > 0) //"wenn ein Datenpaket geliefert wird"
  {//cy5 = Serial.read(); //liest die Daten
 // delay(100);
  cy4 = Serial.read(); 
    delay(100);
  cy3 = Serial.read(); 
    delay(100);
  cy2 = Serial.read(); 
    delay(100);
  cy1 = Serial.read(); 
    delay(100);
 //int y5=cy5-'0';;
 int y4=cy4-'0';;
 int y3=cy3-'0';;
 int y2=cy2-'0';;
 int ay1=cy1-'0';;
//y5=y5 *10000;
y4=y4 *1000;
y3=y3 *100;
y2=y2 *10;
ay1=ay1 *1;
//Serial.println(y5);
Serial.println(y4);
Serial.println(y3);
Serial.println(y2);
Serial.println(ay1);
delay(1000);
Serial.flush(); //seriellen Puffer löschen
  Serial.println(ay1);
 ay1=ay1+y2+y3+y4;
 Serial.println(ay1);
  yposition=(ay1);
 if(ay1<=7501){
  if (ay1>=-1){  
   Stepper3.moveTo(yposition);
 // Zielposition setzen:
  //Stepper2.moveTo (8192);
  // Auf Position fahren mit eingestellter Geschwindigkeit und Beschleunigung:
  Stepper3.runToPosition();
  c=9;
  }}
  else{c=2;}
  }}}
