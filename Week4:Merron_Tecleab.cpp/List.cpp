#include <iostream>
#include <string>
#include "List.h"
#include <vector>
#include "ListNode.h"
#include <fstream>
#include <sstream>

using namespace std;

void List:: append(ListNode *node) {
    if(head == NULL) {
      head = node;
    }

    else {
      ListNode* itr = head;
      while(itr -> next != NULL) {
	itr = itr -> next;
      }
      itr -> next = node;
    }
}


void List:: printList() {
  ListNode * curr = head;
  while(curr != NULL) {
    cout << curr -> value << " -> ";
    curr = curr -> next;
  }
  cout << "NULL";
  
  cout << endl;
}

string vecToString(vector<string> w) {
  for(int i = 0; i < w.size(); i++) {
    string temp = w[i];
    for(int j = 0; j < w[i].size(); j++) {
      cout << w[i][j] << endl;
    }
  }
  return " ";
}

List:: List() { //Initializes the head and the tail for the whole class
  head = NULL;
}


int main() {
  ListNode *h;
  ListNode *m;
  ListNode *n;
  string num1, num2, sentence;
  vector<char> c1, c2, c3;
  vector<char> letters;
  cout << "Type in a sentence: " << endl;
  getline(cin, sentence);
  
  cout << "Type in two numbers" << endl;
  cout << "Number 1: " << endl;
  cin >> num1;
  cout << "Number 2: " << endl;
  cin >> num2;
  cout << "--------" << endl;
  for(int i = 0; i < num1.size(); i++) {
    c1.push_back(num1[i]);
  }
  for(int i = 0; i < num2.size(); i++) {
    c2.push_back(num2[i]);
  }
  List l1;
  List l2;
  List l3;
  cout << "L1: ";
  for(int i = 0; i < c1.size(); i++) {
    ListNode *n = new ListNode(c1[i], NULL);
    l1.append(n);
  }
  l1.printList();
  cout << "L2: ";
  for(int i = 0; i < c2.size(); i++) {
    ListNode *n = new ListNode(c2[i], NULL);
    l2.append(n);
  }
  l2.printList();

  int num1_1 = stol(num1);
  int num2_1 = stol(num2);
  int newNum = num1_1 + num2_1;
  string num3 = to_string(newNum);
  
  for(int i = 0; i < num3.size(); i++) {
    c3.push_back(num3[i]);
  }
  cout << "Output: ";
  for(int i = 0; i < c3.size(); i++) {
    ListNode *n = new ListNode(c3[i], NULL);
    l3.append(n);
  }
  l3.printList();
  cout << "--------" << endl;

  
  List l4;
  List l5;
  int countSpace;
  vector<string> words;
  vector<char> newLetters;
  for(int i = 0; i < sentence.size(); i++) {
    letters.push_back(sentence[i]);
  }
  int startWord = 0;
  
  for(int i = 0; i < sentence.size(); i++) {
    if(letters[i + 1] == ' ') {
      words.push_back(sentence.substr(startWord, (i + 1) - startWord));
      startWord = i + 2;
    }
    else if(letters[i + 1] == letters[sentence.size()]) {
      words.push_back(sentence.substr(startWord, (i + 1) - startWord));
    }
  }
  
  cout << "Input :";
  for(int i = 0; i < letters.size(); i++) {
    ListNode *n = new ListNode(letters[i], NULL);
    l4.append(n);
    if(n -> value == ' ') {
      countSpace++;
    }
  }
  l4.printList();
  string temp;
  int count;
  int swap = words.size();
  while(count != words.size()) {
    for(int j = 1 ; j < swap; j++) {
      temp = words[j];
      words[j] = words[j - 1];
      words[j - 1] = temp;
    }
    count++;
    swap--;
  }
  string temporary;
  for(int i = 0; i < words.size(); i++) {
    for(int j = 0; j < words[i].size(); j++) {
      temporary += words[i][j];
      if(j + 1 == words[i].size() && i + 1 != words.size()) {
	temporary += ' ';
      }
    }
  }
  
  for(int i = 0; i < temporary.size(); i++) {
    newLetters.push_back(temporary[i]);
  }
  cout << "Output: ";
    
  for(int i = 0; i < newLetters.size(); i++) {
    ListNode *n = new ListNode(newLetters[i], NULL);
    l5.append(n);
    if(n -> value == ' ') {
      countSpace++;
    }
  }
  
  l5.printList();
  return 0;
}

