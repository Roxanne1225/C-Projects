/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
  vector<Point<3>> mypoints;
   map<Point<3>, TileImage*> mymap;
   for (auto it = theTiles.begin(); it != theTiles.end(); it++) {
     LUVAPixel mypixel = it->getAverageColor();
     Point<3> mypoint = convertToXYZ(mypixel);
     mypoints.push_back(mypoint);
     mymap[mypoint] = &*it;
   }
   KDTree<3> mytree (mypoints);
   MosaicCanvas * mycanvas  = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
   for (int i = 0; i < mycanvas->getRows(); i++) {
     for (int j = 0; j < mycanvas->getColumns(); j++) {
       Point<3> cur = convertToXYZ(theSource.getRegionColor(i,j));
       Point<3> best = mytree.findNearestNeighbor(cur);
       TileImage * toinsert = mymap[best];
       mycanvas->setTile(i,j,toinsert);
     }
   }
  return mycanvas;
}
