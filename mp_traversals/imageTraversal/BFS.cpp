#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
 void BFS::settrue(Point &point){
   visited[point.x][point.y] = true;
 }
BFS::BFS(const PNG & png, const Point & start, double tolerance) {
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
       }
   }
   queue.push(start);
   visited[start.x][start.y] = true;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */

  return ImageTraversal::Iterator(start_, this);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(2.0);
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  if(point.x < png_.width() && point.y < png_.height() && !visited[point.x][point.y]) {
    if (ImageTraversal::calculateDelta(png_.getPixel(start_.x, start_.y), png_.getPixel(point.x, point.y)) < tolerance_) {
      queue.push(point);
      visited[point.x][point.y] = true;
    }
  }
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  if (queue.empty()) {
    return start_;
  }
  Point ret = queue.front();
  queue.pop();
  return ret;
  return Point(0, 0);
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  return queue.front();
  return Point(0, 0);
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  return queue.empty();
  return true;
}
