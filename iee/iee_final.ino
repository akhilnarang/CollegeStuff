// Including header for DHT sensor
#include <dht.h>
// Setting some constants (the pins that we are using)
const int output=13;
const int ldrDigitalInput=8;
const int input=A4; 
const int DELAY=200;
const int DHT_PIN=4;
int ldrOn;
int on;
dht DHT;


void setup() {
  // Sets the digital pin 13 as output
  pinMode(output, OUTPUT);
  // Sets pin 8 as input from LDR
  pinMode(ldrDigitalInput, INPUT);
  // Starts serial communication at 9600bps
  Serial.begin(9600);
  on=ldrOn=0;
}

void loop() {
  // Read the value from the proximity sensor
  int analogInput = analogRead(input);
  // Read value from LDR
  int digitalInput = digitalRead(ldrDigitalInput);
  // Check various states of the LDR sensor and accordingly move curtain
  if (on && digitalInput) {
    digitalWrite(output, LOW);
    on = ldrOn = 0;
  } else if (!on && !digitalInput && ldrOn) {
    digitalWrite(output, HIGH);
    on = ldrOn = 1;
  } 
  int value = DHT.read11(DHT_PIN);
  // Check the value the sensor is reporting, and accordingly supply voltage at output pin(pin 10) for 5 seconds
  if (analogInput < 200){
    if(!on && !ldrOn) {
      digitalWrite(output, HIGH);
      on=1;
      ldrOn=0;
      delay(DELAY);
    } else if (on) {
      digitalWrite(output, LOW);
      on=0;
      ldrOn=0;
      delay(DELAY);
    }
  }
}
