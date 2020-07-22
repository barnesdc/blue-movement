#include <iostream>
#include "Tree.h"
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

Tree:: Tree() {
  
}


void Tree:: insertNode(TreeNode * rootN, int val) {
  TreeNode * node = new TreeNode();
  node -> value = val;
  TreeNode * temp = new TreeNode();
  queue<TreeNode *> q;
  q.push(rootN);
  
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if(temp -> left == NULL) {
      temp -> left = node;
      return;
    }

    else if(temp -> right == NULL) {
      temp -> right = node;
      return;
    }

    else {
      q.push(rootN -> left);
      q.push(rootN -> right);
    } 
  }
}

void Tree:: leafToRoot(TreeNode * rootN, stack<int> s) {
  if(rootN == NULL) {
    while(!s.empty()) {
      cout << s.top() << " -> ";
      s.pop();
    }
    cout << endl;
    return;
  }

  s.push(rootN -> value);
  leafToRoot(rootN -> left,s);

  if(rootN -> right != NULL) {
    leafToRoot(rootN -> right,s);
  }
  s.pop();
}


void Tree:: mirror(TreeNode * rootN) {
  if(rootN == NULL) {
    return;
  }

  TreeNode * temp = rootN-> right;
  rootN -> right = rootN -> left;
  rootN -> left = temp;
  mirror(rootN -> left);
  mirror(rootN -> right);
}

void Tree:: inOrder(TreeNode * rootN) {
  if(rootN == NULL) {
    return;
  }
  else {
    inOrder(rootN -> left);
    cout << rootN -> value << endl;
    inOrder(rootN -> right);
  }
}

int Tree:: maxDifference(TreeNode * node, int val, int &diff) {
  if(node == NULL) {
    return 32768;
  }
  if(node -> left == NULL && node -> right == NULL) {
    return node -> value;
  }
  int nodeLeft = maxDifference(node -> left, val, diff);
  int nodeRight = maxDifference(node -> right, val, diff);

  if(nodeLeft > nodeRight) {
    val = nodeRight;
    if(diff < node -> value - nodeRight) {
      diff = node -> value - nodeRight;
    }
  }
  else {
    val = nodeLeft;
    if(diff < node -> value - nodeLeft) {
      diff = node -> value - nodeLeft;
    }
  }

  if(node -> value < val) {
    val = node -> value;
  }
  return val;
}

int main() {
  Tree t;
  stack<int> nodes;
  TreeNode * node10 = new TreeNode();
  node10 -> value = 10; //node10 = root
  TreeNode * node20 = new TreeNode();
  node20 -> value = 20;
  TreeNode * node30 = new TreeNode();
  node30 -> value = 30;

  node10 -> left = node20;
  node10 -> right = node30;

  t.insertNode(node10, 14);
  
  t.insertNode(node10, 15);
  t.insertNode(node10, 16);
  t.insertNode(node10, 17);

  cout << "In-Order Traversal: " << endl;
  t.inOrder(node10);
  cout << "----------------" << endl;
  cout << "Leaf-To-Root paths: " << endl;
  t.leafToRoot(node10, nodes);
  t.mirror(node10);
  cout << "----------------" << endl;
  cout << "Mirrored Tree In-Order Traversal: " << endl;
  t.inOrder(node10);
  //Max Difference Test
  cout << "----------------" << endl;
  cout << "Max Difference between a node and its ancestors: " << endl;
  int diffInit = -32768;
  t.maxDifference(node10, -32768, diffInit); 
  cout << diffInit << endl;
  return 0;
}
