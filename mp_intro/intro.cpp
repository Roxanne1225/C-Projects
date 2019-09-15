#include <iostream>


#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using cs225::HSLAPixel;

#include <string>


void rotate(std::string inputFile, std::string outputFile) {
  cs225::PNG input;
  cs225::PNG empty;
  input.readFromFile(inputFile);
  empty.readFromFile(inputFile);
  //bool cs225::PNG::readFromFile(const std::string & inputFile);
  double width = input.width();
  double height = input.height();
  for (unsigned x = 0; x < input.width(); x++) {
    for (unsigned y = 0; y < input.height(); y++) {
      double width2 = width - x - 1;
      double height2 = height - y - 1;
      input.getPixel(width2, height2) = empty.getPixel(x,y);
      input.getPixel(x,y) = empty.getPixel(width2,height2);


    }

  }

      input.writeToFile(outputFile);

  // TODO: Part 2
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  int hu = 100;
  double sat = 0.77;
  double lum = 0.65;
  for (unsigned x = 0; x < png.width(); x++) {
    for (unsigned y = 0; y < png.height(); y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = hu;
      //hu+=10;
      pixel.s = sat;
      //sat++;
      pixel.l = lum;
      pixel.a = 0.8;
    }


  }
  for (unsigned x = (png.width() / 8); x < ( 6 * png.width()/ 8); x++) {
    for (unsigned y = (png.height() / 4); y < (6 * png.height() / 7); y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = 15;
      pixel.s = 0.73;
      pixel.l = 0.9;
      pixel.a = 1;
    }
  }
  for (unsigned x = (2 * png.width() / 8); x < ( 3.5 * png.width()/ 8); x++) {
    for (unsigned y = (4 * png.height() / 7 ); y < (6 * png.height() / 7); y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = hu;
      pixel.s = sat;
      pixel.l = lum;
      pixel.a = 0.8;
    }
  }
  for (unsigned y = (4 * png.height() / 7 ); y < (6 * png.height() / 7); y++) {
    for (unsigned x = (4.5 * png.width() / 8); x < ( 5.3 * png.width()/ 8); x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = hu;
      pixel.s = sat;
      pixel.l = lum;
      pixel.a = 0.8;
    }
  }



  return png;
}
