/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
 #include <cmath>
 #include <iostream>
 using namespace std;
 #include <queue>


//queue<Node*> q;
template <class K, class V>
 int AVLTree<K, V>::getbal( Node* subtree){
   return (heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left));
 }
template <class K, class V>
 bool AVLTree<K, V>::isdeepest( Node* subtree) {
   // if (isbalanced(subtree)) {
   //   return false;
   // }
   if (subtree == NULL) {
     return false;
   }
   if (leftHeavy(subtree)) {
     if (!isbalanced(subtree->left)) {
       return false;
     }
   }
   if (rightHeavy(subtree)) {
     if (!isbalanced(subtree->right)) {
       return false;
     }
   }
   //if (!isbalanced(subtree) && )
   return true;
 }

template <class K, class V>
 bool AVLTree<K, V>::leftHeavy(const Node* subtree) {
   if (subtree == NULL) {
     return false;
   }
   int lHeight = heightOrNeg1(subtree->left);
   int rHeight = heightOrNeg1(subtree->right);

   return (rHeight - lHeight) < -1;
 }
template <class K, class V>
 bool AVLTree<K, V>::rightHeavy(const Node* subtree) {
   if (subtree == NULL) {
     return false;
   }
   int lHeight = heightOrNeg1(subtree->left);
   int rHeight = heightOrNeg1(subtree->right);

  return (rHeight - lHeight) > 1;
 }

template <class K, class V>
int AVLTree<K, V>::heightHelper(Node *root) {
  if (root==NULL)  {
       return 0;
     }
   else
   {
       int lDepth = heightHelper(root->left);
       int rDepth = heightHelper(root->right);

       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}
// template <class K, class V>
// void AVLTree<K, V>::switch(Node *upper, Node *lower){
//
// }
template <class K, class V>
 bool AVLTree<K, V>::isbalanced(Node *root){
   if (root->left == NULL && root->right == NULL) {
     return true;
   }
   //if (root->left != NULL && root->right != NULL) {
     if (abs(heightHelper(root->left) - heightHelper(root->right)) > 1) {
       return false;
     }
     return true;

 }


template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node *temp;
   temp = t->right;
   t->right = temp->left;
 //   if (temp->left_ != NULL) {
 //   temp->left_->parent_ = root;
 // }
   temp->left = t;
    t->height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));
   t = temp;

}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
  //   t->height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));
    rotateRight(t);
    // t->height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node *temp;
   temp = t->left;
   t->left = temp->right;
    t->height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));
 //   if (temp->right_ != NULL) {
 //   temp->right_->parent_ = t;
 // }
   temp->right = t;

   t = temp;
  //  t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
   // t->parent_  = temp;
   // temp->parent_ = NULL;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{

  if (subtree == NULL) {
    return;
  }
  if (!isdeepest(subtree)) {

    return;
  }

  if (rightHeavy(subtree)) {
    if (getbal(subtree->right) > 0) {
      rotateLeft(subtree);
    //  subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
    } else {
      rotateRightLeft(subtree);
    //  subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
    }
  }
  if (leftHeavy(subtree)) {
    if (getbal(subtree->left) < 0) {
      rotateRight(subtree);
      //subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
    } else {
      rotateLeftRight(subtree);
      //subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
    }
  }
  //
  // if (isbalanced(subtree)){
  // //  std::cout<<"is balanced"<<std::endl;
  //
  //   return;
  // }
//
// if (!isdeepest(subtree)) {
//
//   return;
// }
// if (leftHeavy(subtree)) {
//   if (rightHeavy(subtree->left)) {
//     //return TreeNode::leftRight;
//     rotateLeftRight(subtree);
//   }
// //  return TreeNode::right;
// rotateRight(subtree);
// }
// if (rightHeavy(subtree)) {
//   if (leftHeavy(subtree->right)) {
//     rotateRightLeft(subtree);
//   }
// //  return TreeNode::right;
// rotateLeft(subtree);
// }
//return ;




}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here

// if (subtree == NULL) {
//    subtree = new Node(key, value);
//  } else if (key < subtree->key) {
//    insert(subtree->left, key, value);
//   // rebalance(subtree->left);
//     rebalance(subtree);
//  } else if (key > subtree->key){
//    insert(subtree->right, key, value);
//    //rebalance(subtree->right);
//
//     rebalance(subtree);
//  }
//  subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;





if (subtree == NULL) {
      Node * newNode = new Node(key, value);
      subtree = newNode;
  }
  else if (key < subtree->key) {
      insert(subtree->left, key, value);
      rebalance(subtree);
        //subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
  }
  else if (key > subtree->key) {
      insert(subtree->right, key, value);
      rebalance(subtree);
      //   subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
  }
  else if (key == subtree->key) {
      subtree->value = value;
      return;
  }

  subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
}


template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

     if (key < subtree->key) {
        // your code here
      //  std::cout<<"1"<<std::endl;
        remove(subtree->left, key);

      //  std::cout<<"s"<<std::endl;
      //  rebalance(subtree->left);
        //  rebalance(subtree);
        //  subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
    } else if (key > subtree->key) {
        // your code here
      //  std::cout<<"2"<<std::endl;
        remove(subtree->right, key);
      //  std::cout<<"d"<<std::endl;
      //  rebalance(subtree->right);
        //  rebalance(subtree);
      //    subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            //std::cout<<"3"<<std::endl;
            //  subtree->height =  max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) - 1;
            delete subtree;
            //std::cout<<"4"<<std::endl;
            subtree = NULL;
            return;
            //rebalance(subtree);

        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node *temp = subtree->left;
            while (temp->right != NULL) {
              temp = temp->right;
            }
            swap(temp, subtree);
              remove(subtree->left, temp->key);
          //  delete subtree;

            std::cout<<"("<<std::endl;
          //  rebalance(subtree);
             std::cout<<")"<<std::endl;
            return;
              //subtree->height =  max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));

        } else {
            /* one-child remove */
            // your code here
            if (subtree->left != NULL) {
            //  subtree->key = key;
            //std::cout<<"7"<<std::endl;
            Node *tp = subtree->left;
        //    delete subtree;
          //  subtree = NULL;
          subtree->key = tp->key;
          subtree->value = tp->value;
          subtree->left = tp->left;
          subtree->right = tp->right;
              delete tp;
            //  std::cout<<"q"<<std::endl;
            //  rebalance(subtree);
            //  subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
            } else {
            //  std::cout<<"8"<<std::endl;
              Node *tp = subtree->right;
                subtree->key = tp->key;
                subtree->value = tp->value;
                subtree->left = tp->left;
                subtree->right = tp->right;
                delete tp;
                //  subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
            //    std::cout<<"["<<std::endl;
                //rebalance(subtree);
              //  std::cout<<"]"<<std::endl;
            }
        }

        // your code here
    }

    subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
     rebalance(subtree);
}
