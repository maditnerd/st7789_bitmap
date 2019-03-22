#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include <Arduino_ST7789.h> // Hardware-specific library for ST7789 (https://github.com/ananevilya/Arduino-ST7789-Library)

#include "bitmap.h" //(Bitmap generated with LCD Image Converter) https://sourceforge.net/projects/lcd-image-converter/

// This example is based on this tutorial
// https://www.instructables.com/id/Converting-Images-to-Flash-Memory-Iconsimages-for-/
// https://github.com/STEMpedia/eviveProjects/blob/master/imageToFlashMemoryIconsForTFT/
#define TFT_DC    D1
#define TFT_RST   D0
Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(115200);
  Serial.print("ST7789 TFT Bitmap Test");

  tft.init(240, 240);   // initialize a ST7789 chip, 240x240 pixels
  Serial.println("Initialized");

  //uint16_t time = millis();
  tft.fillScreen(BLACK);
  int h = 240, w = 240, row, col, buffidx = 0;
  for (row = 0; row < h; row++) { // For each scanline...
    for (col = 0; col < w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      tft.drawPixel(col, row, pgm_read_word(mercy + buffidx));
      buffidx++;
      delay(0.0001); //Without this delay the wemos crash ?
    }
    Serial.println("Bitmap drawn");
  }
}

void loop() {
}
