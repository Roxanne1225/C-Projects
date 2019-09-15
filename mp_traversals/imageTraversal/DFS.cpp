#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 *
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
 void DFS::settrue(Point &point){
   visited[point.x][point.y] = true;
 }
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  png_ = png;
  current = start;
  start_ = start;
  tolerance_ = tolerance;
  //int i, j;
   int row = png_.width();
   int col = png_.height();

   visited.resize(row);
   for(int i = 0; i < row; i ++)
   {
       visited[i].resize(col);
       for(int j = 0; j <col; j ++)
       {
           visited[i][j] = false;

           //visited[i][j] = 0;
       }
   }
   stack.push(start);
    visited[start.x][start.y] = true;
    //visited[start.x][start.y] = 1;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  visited[start_.x][start_.y] = true;
  return ImageTraversal::Iterator(start_, this);
  return ImageTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(2.0);
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
   std::stack<Point> s;
  if(point.x < png_.width() && point.y < png_.height()) {
    if (visited[point.x][point.y] == false){
    if (ImageTraversal::calculateDelta(png_.getPixel(start_.x, start_.y), png_.getPixel(point.x, point.y)) <= tolerance_) {

      //visited[point.x][point.y] = true;
      //visited[point.x][point.y] = true;
      std::stack<Point> copy;
      while (!stack.empty()){
          if (stack.top() == point) {
            stack.pop();
          } else {
            Point temp = stack.top();
            copy.push(temp);
            stack.pop();
          }
      }
      while (!copy.empty()) {
        Point temp = copy.top();
        stack.push(temp);
        copy.pop();
      }
        stack.push(point);
    }
  }
}
}
// if(point.x < png_.width() && point.y < png_.height()) {
//   if (ImageTraversal::calculateDelta(png_.getPixel(start_.x, start_.y), png_.getPixel(point.x, point.y)) <= tolerance_) {
//   if (visited[point.x][point.y] == 0){
//
//     stack.push(point);
//     //visited[point.x][point.y] = true;
//     visited[point.x][point.y] = 1;
//
// } else if (visited[point.x][point.y] == 1){
//   visited[point.x][point.y] = 2;
// } else {
//   stack.push(point);
// }
// }
// }
// }


/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  if (stack.empty()) {
    return start_;
  }
  Point ret = stack.top();
//  Point ret = stack.front();
  stack.pop();
  visited[ret.x][ret.y] = true;
  return ret;
  return Point(0, 0);
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return stack.top();
//  return stack.front();
  return Point(0, 0);
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return stack.empty();
  return true;
}
