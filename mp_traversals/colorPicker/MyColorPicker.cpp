#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */

  //int hue = 70;
  // HSLAPixel pixel(hue, 1, 0.5);
  // hue += 60;
  // if (hue >= 360) { hue -= 360; }
  // return pixel;
  HSLAPixel p;
if (x % 3 == 0) {
  p = HSLAPixel(80, 1, 0.5);
}
if (x % 4 == 0) {
  p = HSLAPixel(95, 1, 0.5);
}
if (x % 5 == 0) {
  p = HSLAPixel(100, 1, 0.5);
}
if (x % 6 == 0) {
  p = HSLAPixel(105, 1, 0.5);
} else {
  p = HSLAPixel(70, 1, 0.5);
}
return p;
}
