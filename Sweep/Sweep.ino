/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int  inputPin  = 12;  // PIR OUT connected to GPIO 12(D6)
int  led       = 16;  // On Board LED GPIO 16(D0)
bool detect    = false;


void setup() {
  Serial.begin(115200);
  myservo.attach(14);  
  pinMode (inputPin, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {

    myservo.write(0);              // tell servo to go to position in variable 'pos'
    detect = digitalRead(inputPin); // read PIR OUT pin (Movement detected = HIGH)

  if (detect == true) {
    digitalWrite(led, LOW);
    Serial.println("Movement detected");
    Serial.println("Buzzer play");
    /* Method - It creates a "normal distortion" effect on the Buzzer */
    //    buzzer.distortion(NOTE_C3, NOTE_C5);
    //    buzzer.distortion(NOTE_C5, NOTE_C3);

    /* Method - It makes the Buzzer sound */
 
    myservo.write(180);  
    Serial.println(myservo.read());
    delay(3000); 
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
