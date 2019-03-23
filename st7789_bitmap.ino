// This example is based on this tutorial
// https://www.instructables.com/id/Converting-Images-to-Flash-Memory-Iconsimages-for-/
// https://github.com/STEMpedia/eviveProjects/blob/master/imageToFlashMemoryIconsForTFT/

//Don't forget to change User_Setup.h inside TFT_eSPI library !

#include <TFT_eSPI.h>
#include "bitmap.h" //(Bitmap generated with LCD Image Converter) https://sourceforge.net/projects/lcd-image-converter/
TFT_eSPI tft = TFT_eSPI();   // Invoke library

void setup(void) {
  Serial.begin(115200);
  Serial.print("ST7789 TFT Bitmap Test");

  tft.begin();     // initialize a ST7789 chip
  tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness

  tft.fillScreen(TFT_BLACK);
  tft.pushImage(0,0,240,240,mercy);
}

void loop() {
}
