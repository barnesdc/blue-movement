#include <iostream>
#include "ListNode.h"
#include <vector>

#ifndef LIST_H
#define LIST_H

using namespace std;

class List {
 public:
  List();
  void append(ListNode* node);
  void reverseList();
  void printList();
  ListNode *head;
};

#endif
