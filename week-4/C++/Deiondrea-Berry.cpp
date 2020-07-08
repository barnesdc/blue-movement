//I cant get the information into the linkedlist
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Node{
	int val;
  char ch;
	Node * next;
};

//recursive traversal of list to get whole value
string getSumofList(Node*list1){

  if(list1 == NULL) return "";
  else return to_string(list1->val) + getSumofList(list1->next);
}

//insert nodes at beginning of list. (inserts list backwardS)
void insertFirst(Node*&sumList, int num, char c){
	Node * newnode = new Node;
	newnode->val = num;
  newnode->ch = c;
  //first entry
  if(sumList == NULL)
	   newnode->next = NULL;
  else
    newnode->next = sumList;

  sumList = newnode;
}
//add values together and put them in new list
Node*makeSumList( Node *&list1,  Node*&list2){
	Node*newnode = NULL;
	int sum = stoi(getSumofList(list1)) + stoi(getSumofList(list2));

  while(sum>0){
    insertFirst(newnode, sum%10, '\0');
    sum = sum /10;
  }
  return newnode;
}
//print values
void print(Node*printList){
  while(printList != NULL)
  {
    cout << printList -> val << " -> ";
    printList = printList->next;
  }
  cout<<"null";
}

//print chars instead of ints
void print2(Node*printL){
  Node*printList;
  while(printList != NULL)
  {
    cout << printList -> ch << " -> ";
    printList = printList->next;
  }
  cout<<"null";
}
//get string from list
string getString(Node*head){
  Node*current = head;
  if(current == NULL)return "";
  else return current->ch +getString(current->next) ;
}
//each word is sent here and put into the list.
void insertStringFirst(Node*c, string hold){
  for(int i = hold.length()-1 ; i >= 0; --i)
    insertFirst(c, 0, hold[i]);
}

//find spaces in string to seperate all words
void reverseList(Node*list1 , string s){
	Node*c = list1;
  string hold = "";
  int spaceLoc = 0, len = s.length();
  for(int i = 0; i< len; i++)
  {
    spaceLoc = s.find(' '); //find space
    i = 0;
    if(spaceLoc != string::npos){ //if found a space
      hold = s.substr(i,spaceLoc); //send string and space
    } else { //at end
      hold = s.substr(i, spaceLoc -i-1); //only send string
      i = len;
    }
    insertStringFirst(c, hold);
    s = s.substr(spaceLoc +1, len-spaceLoc);
  }
}

int main(){

  cout<< "\tPrompt 1:"<<endl;
  Node * one = NULL, *two = NULL, *sum = NULL;

  insertFirst(one, 3, '\0');
    insertFirst(one, 6, '\0');
      insertFirst(one, 5,'\0');

  insertFirst(two, 2,'\0');
    insertFirst(two, 4,'\0');
      insertFirst(two, 8,'\0');
  sum = makeSumList(one, two);
  cout<< "Adding two lists together: " <<endl;
  print(one); cout<<" + "; print(two); cout<< " = "; print(sum);


  cout<<"\n\n\tPrompt 2:" <<endl;
  one = NULL; two = NULL;

  //put values into string
  char in[] = {"I love Geeks for Geeks\0"};
  int len = strlen(in);
  for(int i = len -1 ; i >=0; --i)
      insertFirst(one, 0, in[i]);

  cout<<"\n Print after insertion.\n ";
  print2(one);

  //reverse string
  string str = getString(one);
  reverseList(one, str);
//print new string
  cout<<"\n Print after reversal. \n ";
  print2(one);
	return 0;
}
