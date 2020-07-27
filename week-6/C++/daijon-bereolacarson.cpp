#include <iostream>
#include <deque>
#include <stdlib.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
};

//Create a new node
Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void newTree(Node* &root){
    root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(8);
    root->right->right = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(7);

}

void printTree(Node* root){
    if(root == NULL)
        return;
    
    cout << root->data << " -> ";
    printTree(root->left);
    printTree(root->right);
}

//1st problem
bool checkLeaf(Node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    else
        return false;
}

void findMinimum(Node* root, int &min){
    if(root == NULL)
        return;
    else{
        if(root->data < min){
            min = root->data;
        } 
    }
    findMinimum(root->left, min);
    findMinimum(root->right, min);
}

void maxDifference(Node* root, int max, int &finalMax){
    int min = 99;
    findMinimum(root, min);
    max = root->data - min;

    if(max > finalMax)
        finalMax = max;
    
    if(!checkLeaf(root)){
        maxDifference(root->left, -1, finalMax);
        maxDifference(root->right, -1, finalMax);
    }
    return;
}

int main(){
    Node* root = NULL;
    newTree(root);
    cout << "Tree: ";
    printTree(root);
    cout << "NULL" << endl;

    int max_diff = -1;
    maxDifference(root, -1, max_diff);
    cout << "Max Difference: " << max_diff << endl;
    return 0;
}