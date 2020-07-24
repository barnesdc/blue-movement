
# I was absent during this day due to personal reasons (which was discussed with Mr. Testman), so the second prompt wasn't fully functional, and I 
# needed a lot of help getting the first part to work.

# Prompt 1: Given two numbers represented by two linked lists, 
# write a function that returns sm list. The sm list is 
# linked list representation of addition of two input numbers.

# create a class for the node, and then 
# for the linked list itself

# node class
class Node:
    def __init__(self, x, nextNode = None):
        self.val = x
        self.next = nextNode

# print method for cleaner output
def printList(head):
    value = []
    while(head):
        value.append(head.val)
        head = head.next
    print(' -> '.join(map(str, value)))

# adds value to linked list
def insert(self, data):
    newNode = Node(data)
    if(self.head):
      current = self.head
      while(current.next):
        current = current.next
      current.next = newNode
    else:
      self.head = newNode

def addTwoLists(head1, head2):
    # c = carry
    sm = head1.val + head2.val
    c = int(sm / 10)

    head3 = Node(sm%10)
    p = head1.next
    q = head2.next
    r = head3
    while(p != None or q != None):
        sm = c + ( p.val if p else 0) + ( q.val if q else 0)
        c = int(sm/10)
        r.next = Node(sm % 10)
        r = r.next
        p = p.next if p else None
        q = q.next if q else None

    if(c > 0):
        r.next = Node(c)

    return head3  

    # Prompt 2: Given a Linked List which represents a sentence S such that each node represents a letter, the 
    # task is to reverse the sentence without reversing individual words.
    
def reverseList(list):
        # initialize variables
        previous = None         
        current = Node(list.val)
        following = current.next    

        # go till the last element of the list
        while current:
            current.next = previous 
            previous = current      
            current = following         
            if following:               
                following = following.next    

        list.head = previous


# 342
head1 = Node(2, Node(4, Node(3)))
printList(head1)

# 465
head2 = Node(5, Node(6, Node(4)))
printList(head2)
head3 = addTwoLists(head1, head2)
printList(head3)

head22 = Node("I", Node("love", Node("Geeks")))
head32 = reverseList(head22)
printList(head32)
