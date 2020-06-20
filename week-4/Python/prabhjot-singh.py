
# Singly Linked List Class
# Class has these methods: 
#   - print(head), prints the data in the linked list starting from head to None
#   - convertStringToLinkedList(string), Converts a given string to Linked List and returns head,tail dict
class LinkedList:
  def __init__(self, data, next=None):
    self.head = data
    self.next = next

  @staticmethod
  def print(linked_list_head):
    ptr = linked_list_head
    while ptr != None:
      print(ptr.data, end="->")
      ptr = ptr.next
    print(None)

  # Returns pointer to head and tail
  # Digits are converted to ints before inserting
  @staticmethod
  def convertStringToLinkedList(string: str):
    for idx, char in enumerate(string):
      toInsert = int(char) if char.isdigit() else char
      if idx == 0:
        ptr = head = LinkedList(toInsert)
      else:
        ptr.next = LinkedList(toInsert)
        ptr = ptr.next
    return {'head': head, 'tail': ptr}

  @staticmethod
  def reverse(linked_list_head):
    ptr = linked_list_head
    prev = None
    while ptr != None:
      next = ptr.next
      ptr.next = prev
      prev = ptr
      ptr = next
    return prev



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
  l1Ptr = L1
  while l1Ptr != None:
    num1 += str(l1Ptr.data)
    l1Ptr = l1Ptr.next

  # Convert L2 to int
  l2Ptr = L2
  while l2Ptr != None:
    num2 += str(l2Ptr.data)
    l2Ptr = l2Ptr.next

  # Convert Sum to Linked List
  sum_string = str(int(num1) + int(num2))
  return LinkedList.convertStringToLinkedList(sum_string)['head']


# Math Solution: Need to reverse the lists though
def sumList2(L1: LinkedList, L2: LinkedList) -> LinkedList:
  l1Ptr = LinkedList.reverse(L1)
  l2Ptr = LinkedList.reverse(L2)
  sum_head = None
  prev = None
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

    toAdd = LinkedList(digit_sum)
    if sum_head: prev.next = toAdd  # Add to end if first node exists
    else: sum_head = toAdd     # Else add as first node
    prev = toAdd

    if l1Ptr != None: l1Ptr = l1Ptr.next
    if l2Ptr != None: l2Ptr = l2Ptr.next

  if carry > 0: toAdd.next = LinkedList(carry)
  return LinkedList.reverse(sum_head)



# Given a Linked List which represents a sentence S such that each node represents a letter, 
# the task is to reverse the sentence without reversing individual words.
# - Example: 
# > Input:  I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->NULL
# > Output: G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->NULL
def reverseWordString(linked_list: LinkedList) -> LinkedList:
  stringList = []

  # Appends the Linked List string. Each element separated by spaces.
  ptr = linked_list
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
    ll_tuple = LinkedList.convertStringToLinkedList(word)

    if idx == 0:
      head = ll_tuple['head']
    else:
      ptr.next = ll_tuple['head']

    ptr = ll_tuple['tail']
    if idx != len(stringList) - 1:  # Prevent space after last word
      ptr.next = LinkedList(' ')
      ptr = ptr.next

  return head



# sumList() Tests
l1 = LinkedList(5, LinkedList(6, LinkedList(3)))
l2 = LinkedList(8, LinkedList(4, LinkedList(2)))
sum1 = sumList1(l1, l2)
LinkedList.print(sum1)
sum2 = sumList2(l1, l2)
LinkedList.print(sum2)
print()

l1 = LinkedList(9, LinkedList(9, LinkedList(9)))
sum1 = sumList1(l1, LinkedList(1))
LinkedList.print(sum1)
sum2 = sumList2(l1, LinkedList(1))
LinkedList.print(sum2)
print()

sum1 = sumList1(LinkedList(0), LinkedList(9))
LinkedList.print(sum1)
sum2 = sumList2(l1, LinkedList(1))
LinkedList.print(sum2)
print()


# reverseWordString() Test
ll_1_head = LinkedList.convertStringToLinkedList('I love Geeks for Geeks')['head']
LinkedList.print(ll_1_head)
LinkedList.print(reverseWordString(ll_1_head))
print()

ll_2_head = LinkedList.convertStringToLinkedList('This is an example test !!')['head']
LinkedList.print(ll_2_head)
LinkedList.print(reverseWordString(ll_2_head))
print()

ll_3_head = LinkedList.convertStringToLinkedList('IBMBootCamp')['head']
LinkedList.print(ll_3_head)
LinkedList.print(reverseWordString(ll_3_head))
print()

ll_4_head = LinkedList.convertStringToLinkedList('IBM BootCamp')['head']
LinkedList.print(ll_4_head)
LinkedList.print(reverseWordString(ll_4_head))


'''  Test cases output
1->4->0->5->None
1->4->0->5->None

1->0->0->0->None
1->0->0->0->None

9->None
1->0->None

I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->None
G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->None

T->h->i->s-> ->i->s-> ->a->n-> ->e->x->a->m->p->l->e-> ->t->e->s->t-> ->!->!->None
!->!-> ->t->e->s->t-> ->e->x->a->m->p->l->e-> ->a->n-> ->i->s-> ->T->h->i->s->None

I->B->M->B->o->o->t->C->a->m->p->None
I->B->M->B->o->o->t->C->a->m->p->None

I->B->M-> ->B->o->o->t->C->a->m->p->None
B->o->o->t->C->a->m->p-> ->I->B->M->None
'''
