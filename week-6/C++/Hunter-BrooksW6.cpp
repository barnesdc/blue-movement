//
//  main.cpp
//  Tree
//
//  Created by Trey Brooks on 7/5/20.
//  Copyright © 2020 Trey Brooks. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <cstddef>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct node{
    int num;
    struct node *left;
   struct node *right;
    
};

struct node* newNode(int newdata){
    node* node = new struct node();
    node->num =newdata;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct node* insert(struct node* root, int key){
    if(root == NULL)
        return newNode(key);
    if(key < root->num)
        root->left = insert(root->left, key);
    else if(key > root->num)
        root->right = insert(root->right,key);
    return
    root;
        
        }

void revinsert(struct node* root){
if(root==NULL)
    return;
     if(root -> left != NULL || root->right != NULL){
   node* node = new struct node();
        node= root->left;
         root->left =root->right  ;
        root-> right=node ;
     }
     revinsert(root->left);
     revinsert(root->right);
     
 }

void printp(int nums[],int len){
    for(int i=(len-1);i >= 0; i--){
        cout << nums[i];}
    cout << endl;
    
    
}

void path(struct node* root,int ops[], int len){
   if(root==NULL)
       return;
    
    ops[len] = root->num;
    len++;
    if(root->left ==NULL && root->right==NULL )
        printp(ops, len);
    else{
    path(root->left,ops,len);
    path(root->right,ops,len);
        }
    
    
}

void printPaths(node* node)
{
    int paths[1000];
    path(node, paths, 0);
}

void printInorder (node* node)
{
    if (node == NULL)
        return;
   
    

    printInorder(node->left);
    printInorder(node->right);

}

int maxdif(node* node,int *h){
   int temp;
    if(node==NULL)
        return *h ;
    if(node -> left == NULL && node->right != NULL)
        return node->num;
  temp = min(maxdif(node->left, h),maxdif(node->right, h) );
    if(*h > (node ->num - temp))
        *h= *h;
        else
            *h= (node->num-temp);
        
    
        return max(temp, node->num);
    
    
    
    
}



int main() {
    int b=0;
    int max;
    node* root = NULL;
   root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 8);
    insert(root, 1);
   
    //preorder(root);
    //printPaths(root);
    //revinsert(root);
    max=maxdif(root, &b);
    cout << max<<endl;
    return 0;
}
