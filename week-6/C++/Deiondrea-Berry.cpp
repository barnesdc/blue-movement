#include <iostream>
#include <deque>
using namespace std;

struct Node{
  int value;
  struct Node*left, *right ;
};

Node* newNode(int val){
   Node* node = new Node;

  node->value = val;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
void makeTree1(Node*&root){
  //level 1
  root = newNode(6);

  //level 2 Left
  root->left = newNode(3);
  //level 2 Right
  root->right= newNode(8);

  //level 3 right
  root->right-> left= newNode(2);
  root->right->right= newNode(4);

  //level 4 Right
  root->right-> left->left= newNode(1);
  root->right-> left->right= newNode(7);

}
void makeTree2(Node*&root){
  //level 1
  root = newNode(1);

  //level 2 Left
  root->left = newNode(2);
  //level 2 Right
  root->right= newNode(3);

  //level 3 left
  root->left->left= newNode(4);
  root->left->right = newNode(5);

  //level 3 right
  root->right-> left= newNode(6);
  root->right->right= newNode(7);

  //level 4 Right
  root->right-> left->left= newNode(8);
  root->right-> left->right= newNode(9);
}
void makeTree3(Node*&root){
  //level 1
  root = newNode(1);

  //level 2 Left
  root->left = newNode(2);
  //level 2 Right
  root->right= newNode(3);

  //level 3 left
  root->left->left= newNode(4);
  root->left->right = newNode(5);

  //level 3 right
  root->right-> left= newNode(6);
  root->right->right= newNode(7);

}
void printTree(Node*root){
  if(root == NULL)
    return;
  //Preorder
  cout<< root->value<<" -> ";
  printTree(root->left);
  printTree(root->right);
}

//Prompt 1 -----------------------------------------------
//check if node is a leaf
bool isLeaf(Node*root){
  if(root->left == NULL &&
     root->right == NULL){
       return true;
     }
  else return false;
}//find minimum descendant
void findMin(Node*root, int &min){
  if(root == NULL) return;
  else
    if( root->value<min) min = root->value;

  findMin(root->left, min);
  findMin(root->right, min);

}
//find the biggest difference between nodes and descendant
void maxDiff(Node*root, int curr_max, int &truemax){
  int min = 999;
  findMin(root, min);
  curr_max = root->value - min;

  if(curr_max > truemax) truemax = curr_max;

  if(!isLeaf(root)){
    maxDiff(root->left, -1, truemax);
    maxDiff(root->right,-1, truemax);
  }
  return;
}

//Prompt 2 -----------------------------------------------
void leaf2roothelper(Node*root, deque<int> route){
    if (root == NULL)
      return;

    route.push_front(root->value);

    if (isLeaf(root)){
      for (int i: route)  cout << i << " -> ";
      cout << "NULL"<< endl;
    }

    leaf2roothelper(root->left, route);
    leaf2roothelper(root->right, route);

    route.pop_back();
}
void leaf2root(Node*root){
    deque<int> route;
    leaf2roothelper(root, route);
}

//Prompt 3 -----------------------------------------------
void swap(Node*root){
  Node* swapper =  root->right;
  root->right = root->left;
  root->left = swapper;
}
void mirror(Node*root){
  if(root == NULL) return;
  swap(root);
  mirror(root->left);
  mirror(root->right);
}

int main(){
  //1
  Node * root = NULL;
  makeTree1(root);
  cout<<"Tree: ";
  printTree(root); cout<<"NULL"<<endl;

  int max_difference = -1;
  maxDiff(root, -1, max_difference);
  cout<<"Max Diff: "<< max_difference<<endl;
  //2
  cout<<"\nPrinted Tree: ";
  Node *root2 = NULL; makeTree2(root2); printTree(root2);
  cout<<endl<<"Leaf to Root Nodes"<<endl;
  leaf2root(root2);

  //3
  Node*root3 = NULL;
  makeTree3(root3);
  cout<<"\nTree before Mirror: "; printTree(root3);
  mirror(root3);
  cout<<"\nTree after Mirror: "; printTree(root3);

}
