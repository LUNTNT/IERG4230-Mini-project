/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Servo.h>
#include "HX711.h"
#include <Wire.h>

ESP8266WiFiMulti WiFiMulti;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

HX711 scale(14, 12);   // 14 = ESP8266 GPIO14(D5), 12 = ESP8266 GPIO12(D6)
float original_weight;
//float calibrate_parameter = 338.13;  // this value is obtained by calibrating the scale with known weights; see the README for details
float calibrate_parameter = 321.44;  // this value is obtained by calibrating the scale with known weights; see the README for details

int pos = 0;    // variable to store the servo position
int  inputPin  = 12;  // PIR OUT connected to GPIO 12(D6)
int  led       = 16;  // On Board LED GPIO 16(D0)
bool detect    = false;


void setup() {
  ESP.wdtDisable();
  ESP.wdtFeed();
  Serial.begin(115200);
  myservo.attach(14);  
  pinMode (inputPin, INPUT);
  pinMode (led, OUTPUT);
  Wire.begin(2,0);

  scale.set_scale(calibrate_parameter);    // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                           // reset the scale to 0

  delay(500);
}

void loop() {

    myservo.write(0);              // tell servo to go to position in variable 'pos'
    detect = digitalRead(inputPin); // read PIR OUT pin (Movement detected = HIGH)

  if (detect == true) {
    digitalWrite(led, LOW);
    Serial.println("Movement detected");
 
    myservo.write(180);  
    Serial.println(myservo.read());
    delay(5000); 
    myservo.write(0);
    Serial.println(myservo.read());
    delay(2000);

    Serial.print("one reading: \t");
    original_weight = scale.get_units(5);
    Serial.print(original_weight, 1);
    Serial.println(" g");

  }
  else {
    digitalWrite(led, HIGH);
    Serial.println("No movement detected");
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(1000); // waits 15 ms for the servo to reach the position
    Serial.println(myservo.read());
  }

  delay(100);

}
