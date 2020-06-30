//Taken from geeksforgeeks
#include <iostream>

using namespace std;

class node{
public:
  int data;
  node* next;
};

int main(){

  node* head = NULL;
  node* second = NULL;
  node* third = NULL;

  //creates 3 nodes
  head = new node();
  second = new node();
  third = new node();

  head->data = 1; //assign 1 to data in first node
  head->next = second; //link first node to second node

  second->data = 2; // assign 2 to data in second node
  second->next = third; //link second node to third node

  third->data = 3; //assign 3 to data in third node
  third-> next = NULL; //makes third node the last one

  return 0;
}
