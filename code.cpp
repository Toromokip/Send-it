#include <Servo.h>
// servo motor variables
int pos = 5;
int status1 = 0;
Servo servo_9;
// solenoid valve variable
int relayPin = 8;
// button and display LEDs
int button = 7;
int led3 = 3; //green
int led1 = 5; //yellow
int led2 = 6; //red
int status = true;
void setup(){
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(button, INPUT_PULLUP);
pinMode(relayPin, OUTPUT);
servo_9.attach(9, 500, 2500); 
}
void loop(){
// start with signal off
digitalWrite(relayPin, HIGH);
// move rotor arm to starting point 5 degrees
servo_9.write(5);
// light red led when program is not started yet
delay(50);
digitalWrite(led2, status);
if (digitalRead(button) == true) {
status = !status;
// green led
digitalWrite(led1, status);
status1 = 0;
while (status1==0 && status == true)
{
delay(1000);
digitalWrite(led3, HIGH);
delay(1000);
// solenoid valve bit
digitalWrite(relayPin, LOW);
delay(3000);
// servo motor bit
for (pos = 5; pos <= 95; pos += 1) {  
  servo_9.write(pos);
  delay(15); 
  }
delay(6000);
for (pos = 95; pos >= 5; pos -= 1) {
  servo_9.write(pos);
  delay(15);
}

status1 = 1;
delay(1000);
digitalWrite(led3, LOW);
}
}
while(digitalRead(button) == true);
delay(50);
}
