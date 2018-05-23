const int output=10;
const int input=A2;

void setup() {
  // Sets the digital pin 10 as output
  pinMode(output, OUTPUT);
  // Starts serial communication at 9600bps
  Serial.begin(9600);
}

void loop() {
  // Read the value from the sensor
  int analogInput = analogRead(input);
  // Display the value in serial monitor incase we need to check it
  Serial.println(analogInput);
  // Check the value the sensor is reporting, and accordingly supply voltage at output pin(pin 10) for 5 seconds
  if (analogInput < 500) {
    digitalWrite(output, HIGH);
    delay(5000);
  } else {
    digitalWrite(output, LOW);
  }
}
