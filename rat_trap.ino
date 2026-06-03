#include <Servo.h>
Servo myServo; // Create a servo object to control the servo motor
const int trigPin = 3; // Trigger pin of ultrasonic sensor
const int echoPin = 4; // Echo pin of ultrasonic sensor
const int servoPin = 9; // PWM pin for servo motor
void setup() {
Serial.begin(9600); // Initialize serial communication
myServo.attach(servoPin); // Attach the servo to specified pin
pinMode(trigPin, OUTPUT); // Set trigger pin as output
pinMode(echoPin, INPUT); // Set echo pin as input
}
void loop() {
long duration, distance;
// Send ultrasonic pulse
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Measure the duration of the pulse
duration = pulseIn(echoPin, HIGH);
// Calculate distance in centimeters
distance = (duration * 0.034) / 2;
// Print distance to serial monitor
Serial.print("Distance: ");
Serial.println(distance);
// Check if an object is detected within 20 cm
if (distance < 20) {
// Rotate servo motor to 90 degrees
myServo.write(90);
} else {
// Rotate servo motor to 0 degrees
myServo.write(0);
}
delay(100); // Delay before next reading
}
