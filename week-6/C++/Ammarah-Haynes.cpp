//constructed nodes from geeksforgeeks

//leaf to root path problem
#include <iostream>
#include<string>
#include<vector>

using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

void printLeaftoRoot(vector<int>list){
  for(int i = list.size() - 1; i >= 0; i--){
    if(i == 0)
      cout << list[i];
    else
      cout << list[i] << "->";
  }
  cout << endl;
}

void leaftoRoot(node* root, vector<int> list){
  if (root == NULL)
    return;
  list.push_back(root->data);
  if (root->left == NULL && root->right == NULL)
    printLeaftoRoot(list);
  leaftoRoot(root->left, list);
  leaftoRoot(root->right, list);
}

void printPath(node* root){
  vector<int> list;
	leaftoRoot(root,list);
}

  struct node* newNode(int data){
    // Allocate memory for new node
    struct node* node = (struct node*)malloc(sizeof(struct node));

    // Assign data to this node
    node->data = data;

    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
  }
  /*    Binary tree
            1
            /\
          2  3
        / \
        4 5
    */
int main(){
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  printPath(root);

  return 0;
}
