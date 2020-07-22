#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <iostream>

using namespace std;

class TreeNode {
 public:
  TreeNode();
  int value;
  TreeNode * left;
  TreeNode * right;

  
 private:
  friend class Tree;

  
};

#endif
