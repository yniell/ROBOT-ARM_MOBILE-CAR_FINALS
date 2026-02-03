//IRremote
#include <IRremote.h> 
const int IRpin = 7;
IRrecv IR(IRpin);

 // Motor 1
const int dir1 = 2;
const int dir2 = 4;
const int speed1 = 3;

// Motor 2 
const int dir3 = 8;
const int dir4 = 12; 
const int speed2 = 9;

//Motor Speed
int MOTSpeed1 = 255;
int MOTSpeed2 = 0;
int MOTSpeed3 = 255;

// Ultrasonic Sensor
const int TRIG = 6;
const int ECHO = 5;
long Duration; 
int Distance; 
const int DStop = .001; 
int t = 500; 
 
void setup() {

IR.enableIRIn();


pinMode(dir1,OUTPUT); 
pinMode(dir2,OUTPUT); 
pinMode(speed1,OUTPUT); 

pinMode(dir3,OUTPUT); 
pinMode(dir4,OUTPUT); 
pinMode(speed2,OUTPUT); 

pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
Serial.begin(9600);
}

void loop() {
   
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

 
  Duration = pulseIn(ECHO, HIGH);
  Distance = (Duration * 0.0343 / 2);

  if (Distance <= DStop) {
    // Motor Stop
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, LOW); 
    digitalWrite(dir4, LOW);
    analogWrite(speed1, MOTSpeed2); // Set speed to MOTSpeed2 (0) to stop
    analogWrite(speed2, MOTSpeed2);
  }
  else{
    while (IR.decode()) {
    if (IR.decodedIRData.decodedRawData == 0xE718FF00) {
      // ARROW UP - FORWARD
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
      digitalWrite(dir3, HIGH);
      digitalWrite(dir4, LOW);
      analogWrite(speed1, MOTSpeed1);
      analogWrite(speed2, MOTSpeed1);

    }
    else if (IR.decodedIRData.decodedRawData == 0xAD52FF00) {
      // ARROW DOWN - REVERSE
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
      digitalWrite(dir3, LOW);
      digitalWrite(dir4, HIGH);
      analogWrite(speed1, MOTSpeed1);
      analogWrite(speed2, MOTSpeed1);

    }
    else if (IR.decodedIRData.decodedRawData == 0xE31CFF00) {
      // OK BUTTON - STOP
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, LOW);
      digitalWrite(dir3, LOW);
      digitalWrite(dir4, LOW);
      analogWrite(speed1, MOTSpeed2); // Set speed to MOTSpeed2 (0) to stop
      analogWrite(speed2, MOTSpeed2);

    }
    else if (IR.decodedIRData.decodedRawData == 0xF708FF00) {
      // LEFT
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
      digitalWrite(dir3, LOW);
      digitalWrite(dir4, HIGH);
      analogWrite(speed1, MOTSpeed3);
      analogWrite(speed2, MOTSpeed3);

    }
    else if (IR.decodedIRData.decodedRawData == 0xA55AFF00) {
      // RIGHT
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
      digitalWrite(dir3, HIGH);
      digitalWrite(dir4, LOW);
      analogWrite(speed1, MOTSpeed3);
      analogWrite(speed2, MOTSpeed3);
      
    }
    IR.resume();
    delay(100);
    
  } 
  
}

  }
