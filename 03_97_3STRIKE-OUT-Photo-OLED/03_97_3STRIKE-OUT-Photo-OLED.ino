#include <Wire.h>
#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays

const int ruptPin = 32;
SSD1306 display(0x3c, 26, 25); //(I2C, SDA, SCL)

void setup() 
{
  display.setFont(ArialMT_Plain_24); //Set Font
  pinMode(ruptPin, INPUT);
  Serial.begin(115200);
}

int interruptCount = 0;

void loop() 
{
  display.init(); //Initialization ディスプレイをリセット
  // display.drawString(0, 0, "START"); //1st low
  // display.display(); //Draw
  // delay(1000);

  if (digitalRead(ruptPin) == LOW) 
  {
    interruptCount++;
    Serial.println("Interrupt!");
    delay(300);
  }
  
  if (interruptCount == 1) 
  {
    display.init(); //Initialization ディスプレイをリセット
    display.drawString(0, 0, "Strike"); //1st low
    // display.drawString(0, 21, "touch"); //2nd low
    // display.drawString(0, 42, "me"); //3rd low
    display.display(); //Draw
    delay(1000);
  }

  else if (interruptCount == 2) 
  {
    display.init(); //Initialization ディスプレイをリセット
    display.drawString(0, 0, "Strike"); //1st low
    display.drawString(0, 21, "2Strike"); //2nd low
    // display.drawString(0, 42, "me"); //3rd low
    display.display(); //Draw
    delay(1000);
  }

  else if (interruptCount == 3) 
  {
    display.init(); //Initialization ディスプレイをリセット
    display.drawString(0, 0, "Strike"); //1st low
    display.drawString(0, 21, "2Strike"); //2nd low
    display.drawString(0, 42, "OUT"); //3rd low
    display.display(); //Draw
    delay(3000);

    display.init(); //Initialization ディスプレイをリセット
    interruptCount = 0;

        
  }
  
  else
  {
    ;
  }

  delay(100); 
  
}
