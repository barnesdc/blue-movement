#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node * left; 
	Node * right;
	Node(int data){
		this->data=data;
		this->left=nullptr;
		this->right=nullptr;
	}
};

//print preorder, printinorder
void printPreOrder(Node * node){
	if(node==nullptr){
		return;
	}

	cout << to_string(node->data)+" ";
	
	printPreOrder(node->left);
	printPreOrder(node->right);
}

void printInOrder(Node * node){
	if(node==nullptr){
		return;
	}

	printInOrder(node->left);
	
	cout<<to_string(node->data)+" ";
	
	printInOrder(node->right);
}

void leafToRoot(Node * node, std::string str);
int findDiff(Node * node);
void findMinMax(Node * node, int * min, int * max);

void leafToRoot(Node * node, std::string str) {
	if(node==nullptr){
		return;
	}
	
	//str+=", ";
	//str+=to_string(node->data);
	str.insert(0, " ");
	str.insert(0, to_string(node->data));
	if(node->left==nullptr && node->right==nullptr){
		cout << str + "\n";
		return;
	}

	leafToRoot(node->left, str);
	leafToRoot(node->right, str);
}

int findDiff(Node * node){
	int min=node->data;
	int max=node->data;
	findMinMax(node, &min, &max);
	return max-min;
}

void findMinMax(Node * node, int * min, int * max) {
	if(node == nullptr){
		return;
	}
	int data = node->data;
	if(data > *max){
		*max=data;
	} else if(data < *min){
		*min = data;
	}

	findMinMax(node->left, min, max);
	findMinMax(node->right, min, max);
}

void mirror(Node * node){
	if(node == nullptr){
		return;
	}

	mirror(node->left);
	mirror(node->right);

	Node * temp = node->right;
	node->right = node->left;
	node->left = temp;
}


int main(){
	//BALANCED
	/*Node * tree = new Node(rand()%20);
	tree->left=new Node(rand()%20);
	tree->right=new Node(rand()%20);
	tree->left->left=new Node(rand()%20);
	tree->left->right=new Node(rand()%20);
	tree->right->right=new Node(rand()%20);
	tree->right->left=new Node(rand()%20);*/

	//LEFT HEAVY //UNCOMMENT FOR RIGHT HEAVY AS WELL
	Node * tree = new Node(rand()%20);
	tree->left=new Node(rand()%20);
	tree->right=new Node(rand()%20);
	tree->left->left=new Node(rand()%20);
	tree->left->right=new Node(rand()%20);
	tree->left->right->left=new Node(rand()%20);
	tree->left->right->right=new Node(rand()%20);

	//RIGHT HEAVY
	mirror(tree);

	//SINGLE PATH THING
	/*Node * tree = new Node(rand()%20);
	tree->right=new Node(rand()%20);
	tree->right->right=new Node(rand()%20);
	tree->right->right->left=new Node(rand()%20);
	tree->right->right->left->right=new Node(rand()%20);*/


	//ACTUAL CODE
	cout<<"PreOrder + InOrder\n";
	printPreOrder(tree);
	cout<<"\n";
	printInOrder(tree);
	cout<<"\n\n";
	
	cout <<"Leaf to Root";
	cout <<"\n";
	leafToRoot(tree, "");
	cout<<"\n";
	
	cout<<"Max Difference\n";
	int diff = findDiff(tree);
	cout << to_string(diff);
	cout<<"\n\n";

	cout <<"Mirror";
	cout <<"\n";
	mirror(tree);
	printPreOrder(tree);
	cout<<"\n";
	printInOrder(tree);
	cout << "\n";
	return 0;
}



