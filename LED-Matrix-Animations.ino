#include <Adafruit_NeoPixel.h>
#define PIN         1  //for hardware acceleration choose 1
#define HEIGHT 12
#define WIDTH 12
#define NUMPIXELS   height*width

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //initialize NeoPixel (library) led-strip

void setup() {
  pixels.begin(); //begin to control the led-strip
}

void loop() {
  middleGrowingAnimation();
  delay(500);
  middleGrowingRingAnimation();
  delay(500);
}

int getPixel(int x, int y){
  if ((x % 2) == 1){
    return (x * WIDTH) + (HEIGHT - 1 - y);
  } else {
    return (x * WIDTH) + y;
  }
}

void middleGrowingAnimation(){
  int x1 = WIDTH/2-1, x2 = WIDTH/2, y1 = HEIGHT/2-1, y2 = HEIGHT/2;
  pixels.clear();
  for (int i = 0; i < HEIGHT/2; i++){
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
}

void middleGrowingRingAnimation(){
  int x1 = WIDTH/2-1, x2 = WIDTH/2, y1 = HEIGHT/2-1, y2 = HEIGHT/2;
  pixels.clear();
  for (int i = 0; i < HEIGHT/2; i++){
    for (int x = x1; x <= x2; x++){
      for (int y = y1; y <= y2; y++){
        pixels.setPixelColor(getPixel(x, y), pixels.Color(30, 0, 0));
      }
    }
     for (int x = x1+1; x <= x2-1; x++){
      for (int y = y1+1; y <= y2-1; y++){
        pixels.setPixelColor(getPixel(x, y), pixels.Color(0, 0, 0));
      }
    }
    pixels.show();
    x1--;
    x2++;
    y1--;
    y2++;
    delay(50);
  }
}
