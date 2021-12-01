/*
  IERG4230 IoT Testing Program
  HX711 Elextronic Scale
  Matter Needing attention:
  On Boot/Reset/wakeup,
  GPIO15(D8) keep LOW and GPIO2(D4)keep HIGH
  GPIO0(D3) HIGH = Run mode / LOW = Flash mode
  On Board LEDs:
  GPIO16(D0)
  GPIO2(D4)

  Connections:
  HX711        ESP8266-12E
  ---------    ---------
  GND          GND
  DT           GPIO14(D5)
  SCK          GPIO12(D6)
  VCC          3V3
*/

#include "HX711.h"
#include <Wire.h>
//#include <Adafruit_GFX.h>     //OLED
//#include <Adafruit_SSD1306.h> //OLED

//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// OLED
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, i2c Addr, Reset share with 8266 reset);
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//HX711 scale(DT, SCK);// parameter "gain" is ommited; the default value 128 is used by the library
HX711 scale(14, 12);   // 14 = ESP8266 GPIO14(D5), 12 = ESP8266 GPIO12(D6)
float unit;

//float calibrate_parameter = 338.13;  // this value is obtained by calibrating the scale with known weights; see the README for details
float calibrate_parameter = 321.44;  // this value is obtained by calibrating the scale with known weights; see the README for details

void setup() {
  ESP.wdtDisable();
  ESP.wdtFeed();
  Serial.begin(115200);
  Wire.begin(2,0);

  //OLED Setup
  //if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
  //  Serial.println(F("SSD1306 allocation failed"));
  //  for (;;);
  //}

  //OLED diplay 1st line
  //display.clearDisplay();
  //display.setTextSize(1);
  //display.setTextColor(WHITE);
  //display.setCursor(0, 10);
  //display.println("IERG 4230 IoT HX711"); // Display static text
  //display.setCursor(0, 30);
  //display.println("Wait, calibrating...."); // Display static text
  //display.display();

  Serial.println("");
  Serial.println("HX711 Demo");
  Serial.println("Before setting up the scale:");
  Serial.print("raw reading: \t");
  Serial.println(scale.read());           // print a raw reading from the ADC

  Serial.print("read average: \t");
  Serial.print(scale.read_average(20));   // print the average of 20 readings from the ADC
  Serial.println(" (20 readings)");

  Serial.print("get value: \t");
  Serial.print(scale.get_value(5));       // print the average of 5 readings from the ADC minus the tare weight (not set yet)
  Serial.println(" (5 readings)");

  Serial.print("get units: \t");
  Serial.print(scale.get_units(5), 1);    // print the average of 5 readings from the ADC minus tare weight (not set) divided
  Serial.println(" (5 readings)");
  // by the SCALE parameter (not set yet)

  scale.set_scale(calibrate_parameter);    // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                           // reset the scale to 0

  Serial.println("After setting up the scale:");
  Serial.print("raw reading: \t");
  Serial.println(scale.read());           // print a raw reading from the ADC

  Serial.print("read average: \t");
  Serial.print(scale.read_average(20));   // print the average of 20 readings from the ADC
  Serial.println(" (20 readings)");

  Serial.print("get value: \t");
  Serial.print(scale.get_value(5));       // print the average of 5 readings from the ADC minus the tare weight, set with tare()
  Serial.println(" (5 readings)");

  Serial.print("get units: \t");
  Serial.print(scale.get_units(5), 1);    // print the average of 5 readings from the ADC minus tare weight, divided by the SCALE parameter set with set_scale
  Serial.println(" (5 readings)");

  Serial.println("Start Readings:");

  //OLED diplay 1st line
  //display.clearDisplay();
  //display.setTextSize(1);
  //display.setTextColor(WHITE);
  //display.setCursor(0, 10);
  //display.println("IERG 4230 IoT HX711"); // Display static text
  //display.setCursor(0, 30);
  //display.println("Start Readings:");     // Display static text
  //display.display();

  delay(500);
}

void loop() {
  Serial.print("one reading: \t");
  unit = scale.get_units(5);
  Serial.print(unit, 1);
  Serial.println(" g");

  //display.clearDisplay();
  //OLED diplay 1st line
  //display.setCursor(0, 10);
  //display.println("IERG 4230 IoT HX711"); // Display static text
  //OLED diplay 3rd line
  //display.setCursor(0, 30);
  //display.println("Start Readings:"); // Display static text

  //OLED diplay 5rd line
  //display.setCursor(0, 50);
  //display.print("One reading:        g");

  //display.setCursor(78, 50);
  //display.print(unit);

  //display.display();

  ESP.wdtFeed();
  //  scale.power_down();			        // put the ADC in sleep mode
  delay(300);
  //  scale.power_up();
}
