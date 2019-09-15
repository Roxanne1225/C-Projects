/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if (first[curDim] == second[curDim]) {
       return first < second;
     }
     if (first[curDim] < second[curDim]) {
       return true;
     }
     else {
       return false;
     }

    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */

     double disTarget = 0;
     for (int i = 0; i < Dim; i++) {
       disTarget += pow( (potential[i] - target[i]), 2);
     }
     double disCurr = 0;
     for (int i = 0; i < Dim; i++) {
       disCurr += pow((target[i] - currentBest[i]), 2);
     }
     if (disTarget < disCurr) {
       return true;
     }
    else if (disTarget == disCurr) {
       return potential < currentBest;
     }
     else {
       return false;
     }
     return false;
}



template <int Dim>
Point<Dim> KDTree<Dim>:: quickselect(vector<Point<Dim>>& list, int left, int right, int k, int dim) {
  std::cout << "1" << endl;
     if (left == right ){       // If the list contains only one element,
         return list[left] ;
       } // return that element
    int pivotIndex  = (right + left) / 2;;    // select a pivotIndex between left and right,
                            // e.g., left + floor(rand() % (right - left + 1))
     pivotIndex  = partition(list, left, right, pivotIndex, dim);
     // The pivot is in its final sorted position
     if (k == pivotIndex){
         return list[k];
       }
     else if (k < pivotIndex){
         return quickselect(list, left, pivotIndex - 1, k, dim);
       }
     else{
         return quickselect(list, pivotIndex + 1, right, k, dim);
       }
}


template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& list, int left, int right, int pivotIndex, int dim)
{
  //function partition(list, left, right, pivotIndex)
  Point<Dim>  pivotValue = list[pivotIndex];
  swap(list[pivotIndex],list[right]);
  int storeIndex = left;
  for (int i = left; i < right; i++) {
    if (smallerDimVal(list[i], pivotValue,dim)) {
      swap(list[storeIndex],list[i]);
      storeIndex++;
    }
  }
  swap(list[right],list[storeIndex]);
  return storeIndex;

}

template <int Dim>
void KDTree<Dim>:: helper(vector<Point<Dim>>& newPoints, int start, int end, int dim, KDTreeNode*& subroot)
{
  if (start > end) {
    return;
  }
  int middle = (start + end) / 2;
  Point<Dim> hold = quickselect(newPoints,start,end,middle,dim);
  subroot = new KDTreeNode(hold);
  size++;
  helper(newPoints,start,middle - 1, (dim + 1) % Dim, subroot -> left);
  helper(newPoints,middle + 1, end, (dim + 1) % Dim, subroot -> right);

}
template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     if (newPoints.size() == 0) {
       root = NULL;
     } else {
       points = newPoints;
  helper(points, 0, newPoints.size() - 1, 0, root);
     }

}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   // KDTreeNode *copy = new KDTreeNode(other.root.point);
   // copy->left = other.left;
   // copy->right = other.right;
   copy(other);
}


template <int Dim>
void KDTree<Dim>::copy(KDTree<Dim>& tocopy) {
  /**
   * @todo Implement this function!
   */
   root = tocopy.root;
 size = tocopy.size();
 points = tocopy.points();
}
template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
      copy(rhs);
   return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   _clean(root);
}

template <int Dim>
void KDTree<Dim>::_clean(KDTreeNode *& subroot){
  //basecase
  if (subroot == NULL) {
    return;
  }
  _clean(subroot -> left);
  _clean(subroot -> right);
  delete subroot;
  subroot = NULL;
}
template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
     Point<Dim> nn = root->point;
         Point<Dim> hold = query;
          _findNearestNeighbor(hold,root,nn,0);
         return nn;
    return Point<Dim>();
}
template <int Dim>
void KDTree<Dim>::_findNearestNeighbor(const Point<Dim>& query, KDTreeNode * subroot, Point<Dim>& curBest, int dim) const {
  if(subroot == NULL) {
    return;
  }
  if (shouldReplace(query,curBest,subroot->point)) {
    curBest = subroot -> point;
  }
  if (smallerDimVal(query,subroot -> point, dim)) {
    if (subroot -> left != NULL) {
     _findNearestNeighbor(query,subroot -> left, curBest, (dim+1)%Dim);
    }
    double podis = pow((query[dim] - (subroot->point)[dim]), 2);
    double curdis = 0;
    for (int i = 0; i < Dim; i++) {
       curdis += pow((query[i] - curBest[i]), 2);
    }
    
    if (curdis >= podis && subroot -> right != NULL) {
       _findNearestNeighbor(query,subroot -> right, curBest, (dim+1)%Dim);
    }
  } else {
    if (subroot -> right != NULL) {
    _findNearestNeighbor(query,subroot -> right, curBest, (dim+1)%Dim);
    }
    double podis = (query[dim] - (subroot->point)[dim])*(query[dim] - (subroot->point)[dim]);
    double curdis = 0.0;
    for (int i = 0; i < Dim; i++) {
       curdis += (query[i] - curBest[i])*(query[i] - curBest[i]);
    }
    if (curdis >= podis && subroot -> left != NULL) {
    _findNearestNeighbor(query,subroot -> left, curBest, (dim+1)%Dim);
    }
  }
  //return curBest;
}
