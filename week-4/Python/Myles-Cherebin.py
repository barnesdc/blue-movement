class Node:
  # constructor
    def __init__(self, data = None, next=None):
        self.data = data
        self.next = next

# A Linked List class with a single head node
class LinkedList:
    def __init__(self):
        self.head = None

    def insert_front(self,Node):
        '''Insert a node at the front of a LinkedList'''
        Node.next = self.head
        self.head = Node

    def insert_behind(self,frNode,node):
        '''Insert a node behind a frNode in a LinkedList'''
        node.next = frNode.next
        frNode.next = node

    def print(self):
      a = self.head
      out = ""
      while (a is not None):
         out = out + str(a.data)
         a = a.next
      return out



#prompt 1
def sum_list(LinkedList1,LinkedList2):
    '''Given two numbers represented by two linked lists, write a function
    that returns sum list. The sum list is linked list representation
    of addition of two input numbers.'''

    out = LinkedList()
    j = LinkedList1.head
    i = LinkedList2.head

    while(i is not None and j is not None ):
        data = i.data + j.data
        temp = Node(data)
        out.insert_behind(out.head,temp)
        i = i.next
        j = j.next
    b = out.head.next
    out.head.next = None
    out.head = b
    return(out)

#prompt 2
def rev_sentence(LinkedList):
    '''Given a Linked List which represents a sentence S such that each node
    represents a letter, the task is to reverse the sentence without
    reversing individual words.'''
    
    out = LinkedList()

    out.head = LinkedList.head
    track = LinkedList.head.next
    while (track is not None):
        if (track.data == ' '):
            out.insert_front(track)
            track=track.next
            if (track != None):
                out.insert_front(track)
                track = track.next
        else:
            out.insert_behind(out.head,track)
            track = track.next
    return(out)
