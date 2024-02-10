#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };


void setup()   {                
  Serial.begin(9600);


  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);

  
  display.clearDisplay();
}
unsigned long previousMillis = 0; 
int count = 0;

void loop() {
  unsigned long currentMillis = millis();  
  if (currentMillis - previousMillis >= 1000) { 
    previousMillis = currentMillis; 
    count++;  // Incrementar a contagem
    displayCount(count);  // Exibir a contagem
  }
}


void displayCount(int count) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.print("Count: ");
  display.println(count);
  display.display();
  delay(1);
}






