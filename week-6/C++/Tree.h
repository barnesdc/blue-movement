#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
#include <stack>

using namespace std;

class Tree {
 public:
  Tree();
  int maxDifference(TreeNode * node, int val, int &diff);
  void insertNode(TreeNode * rootN, int val);
  void inOrder(TreeNode * rootN);
  void leafToRoot(TreeNode * rootN, stack<int> s);
  void mirror(TreeNode * rootN);

};

#endif
