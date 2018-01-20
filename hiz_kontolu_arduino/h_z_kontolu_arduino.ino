#include <SoftPWM.h>
const int trigPin = 9;
const int echoPin = 4;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  SoftPWMBegin();
  SoftPWMSet(5, 0);
  SoftPWMSetFadeTime(5, 10, 10);
    SoftPWMSet(6, 0);
  SoftPWMSetFadeTime(6, 10, 10);
    SoftPWMSet(7, 0);
  SoftPWMSetFadeTime(7, 10, 10);
    SoftPWMSet(8, 0);
  SoftPWMSetFadeTime(8, 10, 10);
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  if (cm < 25 && cm > 14) {
  SoftPWMSet(5, 125);//digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(6, 0);//digitalWrite(6, LOW);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(7, 125);//digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(8, 0);//digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
}
  if (cm < 14 && cm > 12){
  SoftPWMSet(5, 255);//digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(6, 255);//digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(7, 255);//digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(8, 255);//digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
}
  if (cm < 12 && cm > 2) {
  SoftPWMSet(5, 0);//digitalWrite(5, LOW);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(6, 125);//digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(7, 0);//digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(8, 125);//digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  if (cm > 25){
  SoftPWMSet(5, 255);//digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(6, 255);//digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(7, 255);//digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  SoftPWMSet(8, 255);//digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
