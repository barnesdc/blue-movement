#include <iostream>

#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

class ListNode {
 public:
  ListNode();
  ListNode(char value, ListNode* next);
  char value;
  ListNode *next;
  
 private:
  friend class List;
};

#endif
