#include <Adafruit_NeoPixel.h>
#define PIN         1
//#define PIN digitalio.DigitalInOut(board.NEOPIXEL)
//digitalio.DigitalInOut(board.NEOPIXEL)
#define NUMPIXELS   144

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pixels.begin();

  pixels.setPixelColor(5, pixels.Color(50, 0, 0));
  pixels.setPixelColor(6, pixels.Color(50, 0, 0));
  pixels.show();
  delay(1000); 
  pixels.setPixelColor(4, pixels.Color(50, 0, 0));
  pixels.setPixelColor(7, pixels.Color(50, 0, 0));
  pixels.show();
  delay(1000); 
  pixels.setPixelColor(3, pixels.Color(50, 0, 0));
  pixels.setPixelColor(8, pixels.Color(50, 0, 0));
  pixels.show();
  delay(1000); 
  for (int i = 0; i < 12; i++){
    pixels.setPixelColor(i, pixels.Color(0, 50, 0)); 
  }
  pixels.show();
  delay(2000);
  pixels.clear();
}

void loop() {
  /*for (int i = 0; i < 12; i++){
    for (int j = 0; j < 12; j++){
      pixels.setPixelColor(getPixel(i, j), pixels.Color(150, 150, 150));
      pixels.show();
     // delay(2);
    }
  }
  pixels.show();
  delay(1000);
  pixels.clear();
  pixels.show();
  delay(1000);*/
  int x1 = 5, x2 = 6, y1 = 5, y2 = 6;
  for (int i = 0; i < 6; i++){
    for (int x = x1; x <= x2; x++){
      for (int y = y1; y <= y2; y++){
        pixels.setPixelColor(getPixel(x, y), pixels.Color(30, 0, 0));
      }
    }
    pixels.show();
    x1--;
    x2++;
    y1--;
    y2++;
    delay(50);
  }
  delay(500);
  pixels.clear();
  pixels.show();
  delay(500);
  /*
  for (int i = 0; i < 12; i++){
    if (i % 2 == 1){
      for (int j = 11; j >= 0; j--){
        pixels.setPixelColor((i * 12) + j, pixels.Color(150, 0, 0));
        pixels.show();
        delay(200);
      }
    } else {
      for (int j = 0; j < 12; j++){
        pixels.setPixelColor((i * 12) + j, pixels.Color(150, 0, 0));
        pixels.show();
        delay(200);
      }
    }
  }*/

}

int getPixel(int x, int y){
  if ((x % 2) == 1){
    return (x * 12) + (11 - y);
  } else {
    return (x * 12) + y;
  }
}
