
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

//  PNG png;       png.readFromFile("tests/i.png");
PNG png;       png.readFromFile("SOG_Paintings_2500.png");
  FloodFilledImage image(png);


  BFS bfs(png, Point(100, 10), 0.05);
  BFS wfs(png, Point(40, 40), 0.05);
  DFS hfs(png, Point(280, 200), 0.05);
  RainbowColorPicker rainbow(2);
  HSLAPixel p(150, 1, 0.5);
  SolidColorPicker solid(p);
  HSLAPixel f(100, 1, 0.5);
  SolidColorPicker sol(f);
  MyColorPicker my;
  image.addFloodFill( bfs, solid );
  image.addFloodFill( wfs, my );
  image.addFloodFill( hfs, sol );
Animation animation = image.animate(1000);

  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");



  return 0;
}
