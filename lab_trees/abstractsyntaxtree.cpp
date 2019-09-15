#include "abstractsyntaxtree.h"

/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
 double AbstractSyntaxTree::eval(Node *root) const{
   //base case
   if (root == NULL) {
     return 0;
   }

   //char element = root->elem.at(0);
   std::string element = root->elem;

   if (element != "+" && element != "-" && element != "*" && element != "/") {
     return std::stod(root->elem);
   }
      double left;
   if (root->left != NULL) {

   left = eval(root->left);
 }
  double right;
 if (root->right != NULL) {

   right= eval(root->right);
 }

 if (element == "+" ) {
   return left + right;
 }
 if (element == "-" ) {
   return left  -right;
 }
 if (element == "*" ) {
   return left * right;
 }
 if (element == "/" ) {
   return left / right;
 }
 return -1;

 //   if ((root->elem == "+" || root->elem == "-" || root->elem == "*" || root->elem == "/") && (root->left->left == NULL) &&
 // root->right->right == NULL){
 //     if (root->elem == "+") {
 //       return std::stod(root->left->elem) + std::stod(root->right->elem);
 //     }
 //     if (root->elem == "-") {
 //       return std::stod(root->left->elem) - std::stod(root->right->elem);
 //     }
 //     if (root->elem == "*") {
 //       return std::stod(root->left->elem) * std::stod(root->right->elem);
 //     }
 //     if (root->elem == "/") {
 //       return std::stod(root->left->elem) / std::stod(root->right->elem);
 //     }
 //   }
 //   // if (root ->left->left != NULL && root->right->right != NULL) {
 //   //
 //   // }
 //   if (root ->left != NULL && (root->left->elem == "+" || root->left->elem == "-" || root->left->elem == "*" || root->left->elem == "/")) {
 //     return eval(root->left);
 //   }//else{
 //     return 0;
  // }
 }
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...
    Node *root = getRoot();
    return eval(root);
    //return -1;
}
