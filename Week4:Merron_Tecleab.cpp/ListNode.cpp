#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode:: ListNode() {
  value = 'b';
  next = NULL;
}

ListNode:: ListNode(char c, ListNode*n) {
  value = c;
  next = n;
}
