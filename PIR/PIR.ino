/*
  IERG4230 IoT Testing Program
  Passive Infra-Red (PIR) motion detector with Buzzer
  Matter Needing attention:
  On Boot/Reset/wakeup,
  GPIO15(D8) keep LOW and GPIO2(D4)keep HIGH
  GPIO0(D3) HIGH = Run mode / LOW = Flash mode
  On Board LEDs (active LOW):
    GPIO16(D0)
    GPIO2(D4)
  Connections:
  PIR          ESP8266-12E
  ---------    ---------
  VCC          VIN
  OUT          GPIO-12 (D6)
  GND          GND

  Buzzer       ESP8266-12E
  ---------    ---------
  VCC          3.3V
  I/O          GPIO-14 (D5)
  GND          GND
*/
#include "Buzzer.h"

// PIR motion detector
int  inputPin  = 12;  // PIR OUT connected to GPIO 12(D6)
int  led       = 16;  // On Board LED GPIO 16(D0)
bool detect    = false;
Buzzer buzzer(14); // (Buzzer pin)

void setup()
{
  Serial.begin(115200);
  Serial.println("ESP8266-12E/F TPP223 testing program\n");
  Serial.println("Build-in LED at GPIO-16(D0)");
  Serial.println("Buzzer pin at GPIO-14(D5)");
  Serial.println("PIR Detector Pin at GPIO-12(D6)");
  pinMode (inputPin, INPUT);
  pinMode (led, OUTPUT);
}

void loop()
{
  detect = digitalRead(inputPin); // read PIR OUT pin (Movement detected = HIGH)

  if (detect == true) {
    digitalWrite(led, LOW);
    Serial.println("Movement detected");
    Serial.println("Buzzer play");
    buzzer.begin(0);
    /* Method - It creates a "normal distortion" effect on the Buzzer */
    //    buzzer.distortion(NOTE_C3, NOTE_C5);
    //    buzzer.distortion(NOTE_C5, NOTE_C3);

    /* Method - It makes the Buzzer sound */
    buzzer.sound(NOTE_A3, 1); // (Note, duration)
    buzzer.end(100);
  }
  else {
    digitalWrite(led, HIGH);
    Serial.println("No movement detected");
  }

  delay(100);
}
