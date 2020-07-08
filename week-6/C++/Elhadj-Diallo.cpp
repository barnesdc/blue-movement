#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
//--------------------------------------------------------------------------------------------------------------------------
// Elhadj Diallo
// Week-6
// IBM Bootcamp2020.1
//Date: July 7, 2020
//--------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------Prompts-------------------------------------------------------------
/*
Please use a recursion solution for at least one prompt solution.

Find Maximum Difference Between a Node and its Descendants in a Binary Tree. https://ibb.co/563hJSG

Write an algorithm to print leaf to root path for every leaf node of the binary tree. https://ibb.co/G7sZnDZ

Write an algorith to convert a tree to its mirror. https://ibb.co/H40dhCt
*/
//--------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------Node-struct-function------------------------------------------------
struct Node{
    int data;
    Node* left;
    Node* right;
};

void printLeafNodeImp(Node *pNode, vector<int> vector);

//------------------------------------------------------add-function-------------------------------------------------------
Node* add(int data){
    //creat data
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}

//-------------------------------------------------------MaxDiffNode-function----------------------------------------------
/*
Find Maximum Difference Between a Node and its Descendants in a Binary Tree. https://ibb.co/563hJSG
*/

// Helper function to find maximum difference between a node and its
// descendants in a binary tree
int maxDiffNodeHelper(Node* root, int *diff)
{
    // if tree is empty, return INT_MIN
    if (root == NULL)
        return INT_MIN;

    if(root->left== NULL && root->right == NULL){
        return root->data;
    }
    //get the minimum value in the Tree
    int val = min(maxDiffNodeHelper(root->left, diff), maxDiffNodeHelper(root->right, diff));

    // update the maximum difference found so far if required
    *diff = max(*diff, root->data-val);

    //return the min value
    return min(root->data, val);
}

// Find maximum difference between a node and its descendants in a binary tree
int maxDiffNode(Node *root)
{
    //initiate different with infinite min
    int diff = INT_MIN;
    maxDiffNodeHelper(root, &diff);

    return diff;
}
//-------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------printLeafNode-function--------------------------------------------
/*
 * Write an algorithm to print leaf to root path for every leaf node of the binary tree
 * */
void printLeafNode(Node* root){
    if(root == NULL){
        return;
    }
    //creat a vector to store Node->data
    vector<int> arr;
    printLeafNodeImp(root, arr);
}

void printArr(vector<int> arr){
    for(int i= arr.size()-1; i >0; i--){
        cout<< arr[i]<<"->";
    }
    cout << arr[0]<<endl;
}

void printLeafNodeImp(Node *pNode, vector<int> arr) {
    if(pNode == NULL){
        return;
    }
    arr.push_back(pNode->data);
    if(pNode->left == NULL && pNode->right==NULL){
        printArr(arr);
    }

    //traverse to the left
    printLeafNodeImp(pNode->left, arr);
    printLeafNodeImp(pNode->right, arr);
}
//-----------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------mirrorTree-function----------------------------------------------
/*
 * Write an algorith to convert a tree to its mirror.
 * */
// given original tree covert to its mirror tree
// It recurses on both the trees,
void mirrorTree(Node* root, Node** mirror) {
    if (root == NULL) {
        mirror = NULL;
        return;
    }

// Create new mirror node from original tree
    *mirror = add(root->data);
    mirrorTree(root->left, &((*mirror)->right));
    mirrorTree(root->right, &((*mirror)->left));
}
//-----------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------inOrder-function-------------------------------------------------
//function to print inorder traversal.
void inOrder( Node* node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << "->";
    inOrder(node->right);
}


//-----------------------------------------------------------------Test-Cases--------------------------------------------
void mirror_Test_Case(){
    Node* mirror = NULL;
    Node *root = add(1);
    root->left = add(2);
    root->right = add(3);
    root->left->left = add(4);
    root->left->right = add(5);

    /* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    inOrder(root);

    /* Convert tree to its mirror */
    mirrorTree(root, &mirror);

    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    inOrder(mirror);
    cout<<endl;
    cout<<endl;

}
void printLeafNode_Test_Case(){
    Node *root = add(1);
    root->left = add(2);
    root->right = add(3);
    root->left->left = add(4);
    root->left->right = add(5);
    root->right->left = add(6);
    root->right->right= add(7);
    root->right->left->left = add(8);
    root->right->left->right = add(9);
/* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    inOrder(root);
    cout<<endl;

    /* Print inorder traversal of the mirror tree */
    cout << "After Caling printLeafNode function"
         << " \n";
    printLeafNode(root);
}

void maxDiffNode_Test_Case(){
    Node *root = add(6);
    root->left = add(3);
    root->right = add(8);
    root->right->left =add(2);
    root->right->right= add(4);
    root->right->left->left = add(1);
    root->right->left->right = add(7);
/* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    inOrder(root);
    cout<<endl;

    /* Print inorder traversal of the mirror tree */
    cout << "After Caling MaxDiffNode function"
         << " \n";
    cout << maxDiffNode(root);
    cout<<endl;
}
//------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------Main-function-------------------------------------------
int main() {
    maxDiffNode_Test_Case();
    cout<<endl;
    mirror_Test_Case();
    printLeafNode_Test_Case();

    return 0;
}
