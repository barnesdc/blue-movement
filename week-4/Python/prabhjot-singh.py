
# Singly Linked List Class
# Each node has two attributes: data, next
# Class has two static methods: 
#   - print(head), prints the data in the linked list starting from head to None
#   - convertStringToLinkedList(string), Converts a given string to Linked List and returns head,tail dict
class LinkedList:
  def __init__(self, data, next=None):
    self.data = data
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
  def convertStringToLinkedList(string):
    for idx, char in enumerate(string):
      toInsert = int(char) if char.isdigit() else char
      if idx == 0:
        ptr = head = LinkedList(toInsert)
      else:
        ptr.next = LinkedList(toInsert)
        ptr = ptr.next
    return {'head': head, 'tail': ptr}



# Given two numbers represented by two linked lists, write a function that returns sum list. 
# The sum list is linked list representation of addition of two input numbers.
# Example: 
# Input:
#   L1 = 5 -> 6 -> 3 -> NULL
#   L2 = 8 -> 4 -> 2 -> NULL
# Output: 1 -> 4 -> 0 -> 5 -> NULL
def sumList(L1, L2):
  num1 = num2 = ''

  # Convert L1 to int
  l1Ptr = L1
  while l1Ptr != None:
    num1 += str(l1Ptr.data)
    l1Ptr = l1Ptr.next
  num1 = int(num1)

  # Convert L2 to int
  l2Ptr = L2
  while l2Ptr != None:
    num2 += str(l2Ptr.data)
    l2Ptr = l2Ptr.next
  num2 = int(num2)

  # Convert Sum to Linked List
  sum_string = str(num1 + num2)
  return LinkedList.convertStringToLinkedList(sum_string)['head']



# Given a Linked List which represents a sentence S such that each node represents a letter, 
# the task is to reverse the sentence without reversing individual words.
# - Example: 
# > Input:  I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->NULL
# > Output: G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->NULL
def reverseList(linked_list):
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
sum1 = sumList(
  LinkedList(5, LinkedList(6, LinkedList(3))),
  LinkedList(8, LinkedList(4, LinkedList(2)))
)
sum2 = sumList(
  LinkedList(9, LinkedList(9, LinkedList(9))),
  LinkedList(1)
)
sum3 = sumList(LinkedList(0), LinkedList(9))

LinkedList.print(sum1)
LinkedList.print(sum2)
LinkedList.print(sum3)
print()


# reverseList() Test
ll_1_head = LinkedList.convertStringToLinkedList('I love Geeks for Geeks')['head']
LinkedList.print(ll_1_head)
LinkedList.print(reverseList(ll_1_head))
print()

ll_2_head = LinkedList.convertStringToLinkedList('This is an example test !!')['head']
LinkedList.print(ll_2_head)
LinkedList.print(reverseList(ll_2_head))
print()

ll_3_head = LinkedList.convertStringToLinkedList('IBMBootCamp')['head']
LinkedList.print(ll_3_head)
LinkedList.print(reverseList(ll_3_head))
print()

ll_4_head = LinkedList.convertStringToLinkedList('IBM BootCamp')['head']
LinkedList.print(ll_4_head)
LinkedList.print(reverseList(ll_4_head))


'''  Test cases output
1->4->0->5->None
1->0->0->0->None
9->None

I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->None
G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->None

T->h->i->s-> ->i->s-> ->a->n-> ->e->x->a->m->p->l->e-> ->t->e->s->t-> ->!->!->None
!->!-> ->t->e->s->t-> ->e->x->a->m->p->l->e-> ->a->n-> ->i->s-> ->T->h->i->s->None

I->B->M->B->o->o->t->C->a->m->p->None
I->B->M->B->o->o->t->C->a->m->p->None

I->B->M-> ->B->o->o->t->C->a->m->p->None
B->o->o->t->C->a->m->p-> ->I->B->M->None
'''
