/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
 template <typename T>
 void BinaryTree<T>::mirror(Node *root) {
  // Node *root = getRoot();
    //Node *current = root;
   // Node *temp = current->left;
   //    current->left = current->right;
   //    current->right = temp;
   //    return *this;
   //base case
   if (root -> left == NULL && root->right == NULL) {
     return;
   } else {
     Node * temp = root->left;
     root->left = root->right;
     root->right = temp;
     if (root->left != NULL) {
   mirror(root->left);
 }
  if (root->right != NULL) {
   mirror(root->right);
 }
 }
 }
//  template <typename T>
// BinaryTree<T> *BinaryTree<T>::retree(Node *root)
// {
//   return this;
// }

    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    Node *root = getRoot();
    mirror(root);
    //base case
  //
  //   Node *root = getRoot();
  //    Node *current = root;
  //    if (root == NULL) {
  //      return;
  //    }
  //   // if ()
  //   Node *temp = current->left;
  //     current->left = current->right;
  //     current->right = temp;
  //       std::cout << "bef" << std::endl;
  //   //  current = current->left;
  //   if (root->left != NULL) {
  //   retree(root->left)->mirror();
  // }
  //     std::cout << "for1" << std::endl;
  //     if (root->right != NULL) {
  //    retree(root->right)->mirror();
  //  }
  //    return;
    // Node *root = getRoot();
    // Node *current = root;
    // for (int i = 0; i < height() ;i++) {
    //    Node *temp = current->left;
    //    current->left = current->right;
    //    current->right = temp;
    //    current = current->left;
    // }
    // Node *root = getRoot();
    // if (root->left == NULL && root->right == NULL) {
    //   return;
    // }
    // Node *temp = root->left;
    // root->left = root->right;
    // root->right = temp;
    //
    //  (root->left)->mirror();
    // // root->right->mirror();
}


/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
 template <typename T>
 int BinaryTree<T>::max(int a, int b, int c) const{
   if (a > b && a > c) {
     return a;
   }
   if (b > a && b > c) {
     return b;
   }
   return c;
 }
 template <typename T>
 int BinaryTree<T>::min(int a, int b, int c) const{
   if (a < b && a < c) {
     return a;
   }
   if (b < a && b < c) {
     return b;
   }
   return c;
 }
 template <typename T>
 int BinaryTree<T>::maxvalue(Node *root) const{
  //  std::cout << "max" << std::endl;
   if (root->left == NULL && root->right == NULL) {
     return root->elem;
   }
   if (root->left != NULL && root->right != NULL) {
   return max(root->elem, maxvalue(root->left), maxvalue(root->right));
  }
 if (root->left != NULL) {
   return max(root->elem, root->elem, maxvalue(root->left));
 } else {
 //if (root->right != NULL) {
   return max(root->elem, root->elem, maxvalue(root->right));
 }
 }
 template <typename T>
 int BinaryTree<T>::minvalue(Node *root) const{
    //std::cout << "min" << std::endl;
   if (root->left == NULL && root->right == NULL) {
     return root->elem;
   }
   if (root->left != NULL && root->right != NULL) {
   return min(root->elem, minvalue(root->left), minvalue(root->right));
  }
 if (root->left != NULL) {
   return min(root->elem,root->elem, minvalue(root->left));
 } else{
 //if (root->right != NULL) {
   return min(root->elem, root->elem, minvalue(root->right));
 }
 }
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
  //check if a tree is a binary search tree
    // your code here
    Node *root = getRoot();
    for (int i = 0; i < height(root); i++) {
      if (root->left != NULL) {
        if (root->elem < maxvalue(root->left)) {
          // std::cout << "false" << std::endl;
          return false;
        }
      }
      if (root->right != NULL) {
        // std::cout << "right not null" << std::endl;
        if (root->elem > minvalue(root->right)) {
          return false;
        }
      }
      if (root->left != NULL) {
        // std::cout << "update rot" << std::endl;
      root = root->left;
    }
    }
     //std::cout << "did we get out of the for loop" << std::endl;
    root = getRoot();
    for (int i = 0; i < height(root); i++) {
    //   std::cout << "too right" << std::endl;
      if (root->left != NULL) {
        if (root->elem < maxvalue(root->left)) {
          return false;
        }
      }
      if (root->right != NULL) {
        if (root->elem > minvalue(root->right)) {
          return false;
        }
      }
      if (root->right != NULL) {
            root = root->right;
          }
    }

//     Node *root = getRoot();
//
//     for (int i = 0; i < height(root); i++) {
//       Node *left = root->left;
//       Node *right = root->right;
//       if (left != NULL && right != NULL) {
//       if (left->elem > root->elem || right->elem < root->elem) {
//         return false;
//       } else {
//         root = root->left;
//       }
//     } else {
//       if (left != NULL) {
//       root = root->right;
//     }
//     if (right != NULL) {
//       root = root->left;
//     }
//     }
//   }
//   for (int i = 0; i < height(root); i++) {
//     Node *left = root->left;
//     Node *right = root->right;
//     if (left != NULL && right != NULL) {
//     if (left->elem > root->elem || right->elem < root->elem) {
//       return false;
//     } else {
//       root = root->right;
//     }
//   } else {
//     if (left != NULL) {
//     root = root->right;
//   }
//   if (right != NULL) {
//     root = root->left;
//   }
//   }
// }
    return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
 template <typename T>
 bool BinaryTree<T>::isOrderedRecursive(Node *root) const{
   //base case;

   if (root ->left == NULL && root->right == NULL) {
     return true;
   }
   if (root->left != NULL) {
   if (maxvalue(root->left) > root->elem) {
     return false;
   }
 }
 if (root ->right != NULL) {
   if (minvalue(root->right) < root->elem) {
     return false;
   }
 }
 if (root->left != NULL && root ->right != NULL) {
   return (isOrderedRecursive(root->left) && isOrderedRecursive(root->right));
 }
 if (root->left != NULL) {
   return (isOrderedRecursive(root->left));
 } else {
   return isOrderedRecursive(root->right);
 }
  // return true;
 }
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    //base case
    Node *root = getRoot();
    return isOrderedRecursive(root);
  //  return false;
}


/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
 template <typename T>
 int BinaryTree<T>::numNodes(Node *root) const
{
  if (root->left == NULL && root ->right == NULL) {
    return 1;
  }
  if (root->left != NULL && root->right != NULL) {
    return numNodes(root->left) + numNodes(root->right);
  }
  if (root->left != NULL) {
    return numNodes(root->left);
  }  else {
    return numNodes(root->right);
  }
}


template <typename T>
void BinaryTree<T>::storePath(std::vector<std::vector<T>>& paths, std::vector<T> path, int curNum, int *start) const
{
  paths.resize(*start);
  paths[*start - 1].resize(curNum);
  for (int i = 0; i < curNum; i++) {
    paths[*start - 1][i] = path[i];
  }
  //(*start)++;
  return;
}
template <typename T>
void BinaryTree<T>::getPathRecur(Node *root, std::vector<std::vector<T>>& paths, std::vector<T>& path, int *start, int curNum) const{
  if (root==NULL){
    std::cout << "nu" << std::endl;
    return;
  }
  //std::cout << root->elem << std::endl;
//std::vector<T> path;
//std::vector<T> path(numLeaves-1);

// if (start >= numLeaves) {
//   return;
// } else {
//std::cout << "in else" << std::endl;
//  std::cout << start << std::endl;
//  std::cout << root->elem << std::endl;
  path[curNum]= root->elem;
//    std::cout << "here" << std::endl;
  curNum++;
//paths[start] = v;
//}
//start++;
  /* it's a leaf, so print the path that led to here  */
  if (root->left==NULL && root->right==NULL)
  {
    //  std::cout << "1" << std::endl;
    (*start)++;
    std::cout << start << std::endl;
    std::cout << "here" << std::endl;
    storePath(paths, path, curNum, start);
  //  start++;
    //curNum++;
    //  std::cout << "after store" << std::endl;
  //  return;
    // for (int i = 0; i < pathlenght; i++) {
    // v[i] =
    // }
    // printArray(path, pathLen);
  }
    /* otherwise try both subtrees */
  //  if (root->left != NULL) {
    //  start++;
      std::cout << start << std::endl;
    getPathRecur(root->left, paths, path, start, curNum);
    //  std::cout << "2" << std::endl;
  //} else {
  //  start++;
    getPathRecur(root->right, paths, path, start, curNum);
  //}

//   paths[start] = v;
//   if (start < numLeaves) {
//   start++;
// } else {
//   return;
// }

}

template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths) const
{
    // your code here

        Node *root = getRoot();
    std::cout << numNodes(root) << std::endl;
  //  int numofPaths = numNodes(root);
    std::vector<T> path(pow(2, height()+1) -1);
    int *start = new int;
    int curNum = 0;
    *start = 0;

    //std::vector<std::vector<T>> hay(numofPaths);
    //std::vector<T> v;
  //  for (int i = 0; i < numofPaths; i++) {
  //delete start;
      getPathRecur(root, paths,path, start, curNum);
        //std::cout << "out" << std::endl;
    delete start;
    start = NULL;
      //paths[i]
  //  }
  //  paths = hay;

}


/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
 template <typename T>
 int BinaryTree<T>::sumDistances(Node *root) const
 {
   if (root ->left == NULL && root->right == NULL) {
     return 1;
   }
   if (root->left != NULL && root->right != NULL) {
     return sumDistances(root->left) + sumDistances(root->right) +2;
   }
   if (root->left != NULL) {
     return 1+ sumDistances(root->left);
   }
   else {
     return 1+ sumDistances(root->right);
   }
 }
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    Node *root = getRoot();
    return sumDistances(root);
    //return -1;
}
