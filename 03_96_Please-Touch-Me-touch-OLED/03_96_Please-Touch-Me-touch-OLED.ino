// ジョークグッズ　可愛いペットやキャラクターに取り付ける帽子(touch)、札(OLED)で演出
#include <Wire.h>
#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays
const int touchPin = 32;

SSD1306 display(0x3c, 26, 25); //(I2C, SDA, SCL)
//Uses I2C, connectorB only
 
void setup() {
  display.setFont(ArialMT_Plain_24); //Set Font
  pinMode(touchPin, INPUT);
}
 
void loop() {
  
  if (digitalRead(touchPin) == HIGH) 
  {
    display.init(); //Initialization ディスプレイをリセット
    display.drawString(0, 0, "Don't"); //1st low
    display.drawString(0, 21, "touch"); //2nd low
    display.drawString(0, 42, "me"); //3rd low
    display.display(); //Draw
    delay(1000);
  }
  else {
    display.init(); //Initialization ディスプレイをリセット
    display.drawString(0, 0, "Please"); //1st low
    display.drawString(0, 21, "touch"); //2nd low
    display.drawString(0, 42, "me"); //3rd low
    display.display(); //Draw
    delay(1000);
  }
}
