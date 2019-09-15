#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
}
ImageTraversal::Iterator::Iterator(double a) {
  /** @todo [Part 1] */
  traversal = NULL;
}


ImageTraversal::Iterator::Iterator(Point start, ImageTraversal *tra) {
  /** @todo [Part 1] */
  start_ = start;
  traversal = tra;
  traversal->add(start);
//  current = start;
  traversal->settrue(start);
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  if (traversal->empty()) {
    Point c = *(*this);
    traversal->settrue(c);
    return *this;
  }
  Point current = traversal->pop();
  //traversal->visited[current.x][current.y] = true;
  traversal->settrue(current);
  // traversal->add(start_);
  // std::cout<<"here"<<std::endl;
  Point ptright = Point((current.x) + 1, current.y);
  Point ptbelow = Point(current.x, (current.y) + 1);
  Point ptleft = Point((current.x) - 1, current.y);
  Point ptup = Point(current.x, (current.y) - 1);
  traversal->add(ptright);
  traversal->add(ptbelow);
  traversal->add(ptleft);
  traversal->add(ptup);
//   if (!traversal->empty()){
//   Point c = traversal->peek();
//   traversal->settrue(c);
// }
//   traversal->add(ptup);
//   traversal->add(ptleft);
// traversal->add(ptbelow);
//   traversal->add(ptright);
//
// current = traversal->pop();
// traversal->add(current);
// current = traversal->peek();
  // while (!traversal->empty()){
  //   std::cout<<"!"<<std::endl;
  //   current = traversal->pop();
  // }
  //  traversal->add(current);
  // std::cout<<"@"<<std::endl;
  // while(!traversal->empty()){
  //      Point curr = traversal->peek();
  //      if(traversal->visited[curr.x][curr.y]){
  //        traversal->pop();
  //     //   curr = Point(11111,11111);
  //      }
  //      else{
  //        break;
  //      }
  //    }

  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return traversal->peek();
  return Point(0, 0);
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  //return traversal != other.traversal;
  bool thisEmpty = false;
  bool otherEmpty = false;

  if (traversal == NULL) { thisEmpty = true; }
  if (other.traversal == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = traversal->empty(); }
  if (!otherEmpty) { otherEmpty = other.traversal->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the traversals are equal, return true
  else if ((!thisEmpty)&&(!otherEmpty)) return (traversal != other.traversal); //both not empty then compare the traversals
  else return true;
  }
  //return false;
//}
