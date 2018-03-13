#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservobottom;
Servo myservotop;         //50 ile 180 arasında calısır.

int counterInterrupt = 0;

int msgTXT = 0;
int valbottom = 90;
int valtop = 90;


void setup()
{
  Serial.begin(9600);//HABERLESME

  myservobottom.attach(7);//SERVOALT
  myservotop.attach(8);//SERVOUST

  Serial.println("programStarting...");
}

void loop() {
  /*****************************************oku*/
  if (Serial.available()) {
    msgTXT = Serial.read();
    Serial.println(msgTXT);
    
    if (msgTXT == 97) {
      valbottom = valbottom + 10;
    }
    if (msgTXT == 122) {
      valtop = valtop + 10;
    }
    else if (msgTXT == 115) {
      valbottom = valbottom - 10;
    }
    else if (msgTXT == 120) {
      valtop = valtop - 10;
    }
    else if (msgTXT == 48) {
      valbottom = 90;
      valtop = 90;
    }
    else if (msgTXT == 49) {
      valbottom = 150;
      valtop = 150;
    }
    else {
      Serial.println("HATALı TUS");
    }
    Serial.print(valbottom);
    Serial.print(" , ");
    Serial.println(valtop);
  }
  /*****************************************degerlendir*/
  if (valbottom <= 5) {
    valbottom = 10;
    Serial.println("MINIMUM LIMIT");
  }
  else if (valtop <= 5) {
    valtop = 10;
    Serial.println("MINIMUM LIMIT");
  }
  else if (valbottom >= 175) {
    valbottom = 170;
    Serial.println("MAKSIMUM LIMIT");
  }
  else if (valtop >= 175) {
    valtop = 170;
    Serial.println("MAKSIMUM LIMIT");
  }
  /*****************************************yap*/
  myservobottom.write(valbottom);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  myservotop.write(valtop);                  // sets the servo position according to the scaled value
  delay(15);   
}

