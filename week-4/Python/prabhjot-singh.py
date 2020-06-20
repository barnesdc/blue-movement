
# Singly Linked List Node Class
# Each node has two attributes: data, next
class LinkedListNode:
  def __init__(self, data, next=None):
    self.data = data
    self.next = next


# Singly Linked List Class
# Class has these methods: 
#   - print(head), prints the data in the linked list starting from head to None
#   - insertBeginning(data), Inserts a Node at the beginning
#   - insertEnd(data), Inserts a Node at the end and returns tail ptr
#   - convertStringToLinkedList(string), Converts a given string to Linked List and returns head,tail dict
#   - reverse(head), reverses the Linked List and returns the head
class LinkedList:
  def __init__(self):
    self.head = None

  # Prints the Linked List
  def print(self):
    ptr = self.head
    while ptr != None:
      print(ptr.data, end="->")
      ptr = ptr.next
    print(None)

  # Inserts a Node at the beginning of Linked List
  def insertBeginning(self, data):
    node = LinkedListNode(data, self.head)
    self.head = node

  # Inserts a Node at the end of Linked List and returns pointer to tail
  def insertEnd(self, data):
    node = LinkedListNode(data)
    if self.head == None:
      self.head = node
      return node
    ptr = self.head
    while ptr.next != None:
      ptr = ptr.next
    ptr.next = node
    return node

  # Creates a Linked List from a string and returns pointer to tail
  # Digits are converted to ints before inserting
  def convertStringToLinkedList(self, string: str) -> LinkedListNode:
    for idx, char in enumerate(string):
      toInsert = int(char) if char.isdigit() else char
      if idx == 0:
        ptr = self.head = LinkedListNode(toInsert)
      else:
        ptr.next = LinkedListNode(toInsert)
        ptr = ptr.next
    return ptr

  # Reverses the Linked List
  def reverse(self):
    ptr = self.head
    prev = None
    while ptr != None:
      next = ptr.next
      ptr.next = prev
      prev = ptr
      ptr = next
    self.head = prev



# Given two numbers represented by two linked lists, write a function that returns sum list. 
# The sum list is linked list representation of addition of two input numbers.
# Example: 
# Input:
#   L1 = 5 -> 6 -> 3 -> NULL
#   L2 = 8 -> 4 -> 2 -> NULL
# Output: 1 -> 4 -> 0 -> 5 -> NULL

# Int <-> String Conversion Solution
def sumList1(L1: LinkedList, L2: LinkedList) -> LinkedList:
  num1 = num2 = ''

  # Convert L1 to int
  l1Ptr = L1.head
  while l1Ptr != None:
    num1 += str(l1Ptr.data)
    l1Ptr = l1Ptr.next

  # Convert L2 to int
  l2Ptr = L2.head
  while l2Ptr != None:
    num2 += str(l2Ptr.data)
    l2Ptr = l2Ptr.next

  # Convert Sum to Linked List
  sum_string = str(int(num1) + int(num2))
  sum_LL = LinkedList()
  sum_LL.convertStringToLinkedList(sum_string)
  return sum_LL


# Math Solution: Need to reverse the lists though
def sumList2(L1: LinkedList, L2: LinkedList) -> LinkedList:
  L1.reverse(); L2.reverse()
  l1Ptr = L1.head
  l2Ptr = L2.head
  sum_LL = LinkedList()
  carry = 0

  while l1Ptr != None or l2Ptr != None:
    l1_digit = l1Ptr.data if l1Ptr else 0
    l2_digit = l2Ptr.data if l2Ptr else 0

    digit_sum = l1_digit + l2_digit + carry
    if digit_sum >= 10:
      digit_sum = digit_sum - 10
      carry = 1
    else:
      carry = 0

    sum_LL.insertBeginning(digit_sum)
  
    if l1Ptr != None: l1Ptr = l1Ptr.next
    if l2Ptr != None: l2Ptr = l2Ptr.next

  if carry > 0: sum_LL.insertBeginning(carry)
  return sum_LL



# Given a Linked List which represents a sentence S such that each node represents a letter, 
# the task is to reverse the sentence without reversing individual words.
# - Example: 
# > Input:  I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->NULL
# > Output: G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->NULL
def reverseWordString(linked_list: LinkedList) -> LinkedList:
  stringList = []

  # Appends the Linked List string. Each element separated by spaces.
  ptr = linked_list.head
  string = ''
  while ptr != None:
    if ptr.data == ' ':
      stringList.append(string)
      string = ''
    else:
      string += ptr.data
    ptr = ptr.next
  stringList.append(string)
  
  # Reverse and Convert words to Linked List
  for idx, word in enumerate(reversed(stringList)):
    ll_toAdd = LinkedList()
    ll_toAdd.convertStringToLinkedList(word)

    if idx == 0:
      reversed_word_LL = ll_toAdd
    else:
      tail.next = ll_toAdd.head

    if idx != len(stringList) - 1:  # Prevent space after last word
      tail = ll_toAdd.insertEnd(' ')

  return reversed_word_LL



# sumList() Tests
nums1 = ['563', '999', '0']
nums2 = ['842', '1', '9']

for i in range(len(nums1)):
  l1 = LinkedList();  l2 = LinkedList()

  for digit in nums1[i]:
    l1.insertEnd(int(digit))
  for digit in nums2[i]:
    l2.insertEnd(int(digit))

  print(nums1[i] + ' + ' + nums2[i])
  sum1_LL = sumList1(l1, l2); print('sumList1: ', end=''); sum1_LL.print()
  sum2_LL = sumList2(l1, l2); print('sumList2: ', end=''); sum2_LL.print()
  print()


# reverseWordString() Test
sentences = [
  'I love Geeks for Geeks',
  'This is an example test !!',
  'IBMBootCamp',
  'IBM BootCamp'
]

for sentence in sentences:
  ll = LinkedList()
  ll.convertStringToLinkedList(sentence)
  print('Before:', end='\t');  ll.print()
  ans = reverseWordString(ll) 
  print('After:', end='\t');   ans.print()
  print()


'''  Test cases output
563 + 842
sumList1: 1->4->0->5->None
sumList2: 1->4->0->5->None

999 + 1
sumList1: 1->0->0->0->None
sumList2: 1->0->0->0->None

0 + 9
sumList1: 9->None
sumList2: 9->None

Before: I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->None
After:  G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->None

Before: T->h->i->s-> ->i->s-> ->a->n-> ->e->x->a->m->p->l->e-> ->t->e->s->t-> ->!->!->None
After:  !->!-> ->t->e->s->t-> ->e->x->a->m->p->l->e-> ->a->n-> ->i->s-> ->T->h->i->s->None

Before: I->B->M->B->o->o->t->C->a->m->p->None
After:  I->B->M->B->o->o->t->C->a->m->p->None

Before: I->B->M-> ->B->o->o->t->C->a->m->p->None
After:  B->o->o->t->C->a->m->p-> ->I->B->M->None
'''
