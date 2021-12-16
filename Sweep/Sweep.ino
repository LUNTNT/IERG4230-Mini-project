/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <Servo.h>

#include "HX711.h"

#include <Wire.h>

#ifndef STASSID
#define STASSID "4230_GP01"
#define STAPSK  "12345678"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

HX711 scale(14, 12);  // 14 = ESP8266 GPIO14(D5), 12 = ESP8266 GPIO12(D6)
int  pir       = 4;  // D2
int  led       = 16;  // On Board LED GPIO 16(D0)
int  servopin  = 5;  // D1

//float calibrate_parameter = 338.13;  // this value is obtained by calibrating the scale with known weights; see the README for details
float calibrate_parameter = 321.44;  // this value is obtained by calibrating the scale with known weights; see the README for details

int pos = 0;    // variable to store the servo position
bool detect    = false;
bool eating    = false;

void feedHandler() {
  int feedtime;
  float org_w, new_w;
  
  if (server.argName(0) == "time"){
    String temp = server.arg(0);
    feedtime = temp.toInt();
  } else {
    server.send(500, "text/plain", "No Time Value");
  }

  Serial.println("GET: Starting to drop fodder");
  org_w = scale.get_units(5);
  delay(500);

  myservo.write(180);  
  delay(feedtime * 1000); 
  myservo.write(0);
  
  Serial.println("End of dropping fodder");
  delay(500);
  
  Serial.print("Feed Time End. Scale Increased: \t");
  new_w = scale.get_units(5);
  Serial.print(new_w - org_w, 1);
  Serial.println(" g");

  server.send(200, "application/json", "{\"original weight\":"+String(org_w)+",\"new weight\":"+String(new_w)+"}");
}

void weightHandler() {
  float original_weight;

  Serial.print("GET: One reading: \t");
  original_weight = scale.get_units(5);
  Serial.print(original_weight, 1);
  Serial.println(" g");

  server.send(200, "application/json",  "{\"weight\":"+String(original_weight)+"}");
}

void setup() {

  Serial.begin(115200);

  //Hardware Setup
  myservo.attach(servopin);  
  myservo.write(0);

  //PIR SETUP
  pinMode (pir, INPUT);
  pinMode (led, OUTPUT);
  
  Wire.begin(2,0);

  //SCALE INIT
  scale.set_scale(calibrate_parameter);    // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                           // reset the scale to 0



  //WIFI SETUP
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting to connect...");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  //SERVER ROUTE SETUP
  server.on("/feed", feedHandler);
  server.on("/weight", weightHandler);
  server.begin();
  Serial.println("HTTP server started");
  
  
  delay(500);
}

float original_weight, new_weight;

void loop() {


  //Server 
  server.handleClient();
  MDNS.update();

  //Init PIR
  detect = digitalRead(pir); // read PIR OUT pin (Movement detected = HIGH)

  //PIR
  if (detect == true && eating == false) {
    Serial.println("Movement detected");

    Serial.print("Read Original Weight: \t");
    original_weight = scale.get_units(5);
    Serial.print(original_weight, 1);
    Serial.println(" g");

    delay(5000);
    Serial.print("Read New Weight: \t");
    new_weight = scale.get_units(5);
    Serial.print(new_weight, 1);
    Serial.println(" g");

    if (original_weight - new_weight >= 2) {
      Serial.println("Eating detected");
      eating = true;
      digitalWrite(led, LOW);
    }
  }
  
  if (detect == true && eating == true) {
    Serial.print("Eating continous: \t");
    new_weight = scale.get_units(5);
    Serial.print(new_weight, 1);
    Serial.println(" g");
  }

  if (detect == false && eating == true) {
    float temp_weight;
    Serial.print("Detect eating: \t");
    temp_weight = scale.get_units(5);
    Serial.print(temp_weight, 1);
    Serial.println(" g");

    delay(5000);
    Serial.print("Read New Weight: \t");
    new_weight = scale.get_units(5);
    Serial.print(new_weight, 1);
    Serial.println(" g");

    if (temp_weight - new_weight <= 2) {
      Serial.println("Eating ended");
      eating = false;
      digitalWrite(led, HIGH);
    }
  }
  
  if (detect == false && eating == false) {
    digitalWrite(led, HIGH);
  }

  delay(5000);

}
