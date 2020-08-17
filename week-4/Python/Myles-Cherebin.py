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
            out = out + str(a.data) + "->"
            a = a.next

        out += "NULL"

        print(out)

#prompt 1
def sum_list(LinkedList1,LinkedList2):
    '''Given two numbers represented by two linked lists, write a function
    that returns sum list. The sum list is linked list representation
    of addition of two input numbers.'''

    out = LinkedList()
    j = LinkedList1.head
    i = LinkedList2.head

    one = ""
    two = ""

    while(i is not None or j is not None):
        if i is not None:
            one += str(i.data)
            i = i.next
        if j is not None:
            two += str(j.data)
            j = j.next

    one = int(one)
    two = int(two)

    sum = one + two
    sum = str(sum)

    out.head = Node(sum[0])
    j = out.head
    for i in range(1, len(sum)):
        temp = Node(sum[i])
        out.insert_behind(j,temp)
        j = j.next


    return(out)

#prompt 2
def rev_sentence(LList):
    '''Given a Linked List which represents a sentence S such that each node
    represents a letter, the task is to reverse the sentence without
    reversing individual words.'''

    out = LinkedList()
    current = LList.head
    notyet = LList.head.next
    endWord = current
    current.next = None

    out.head = current
    current = notyet
    notyet = notyet.next
    current.next = None

    while (current is not None):
        if (current.data == " "):
            out.insert_front(current)
            current = notyet
            notyet = notyet.next
            current.next = None

            if (current):
                out.insert_front(current)
                endWord = current
                current = notyet
                notyet = notyet.next
                current.next = None
        else:
            if out.head.next == " ":
                out.insert_behind(out.head,current)
            else:
                out.insert_behind(endWord, current)
            endWord = current
            current = notyet
            if notyet is not None:
                notyet = notyet.next
                current.next = None

    return(out)

if __name__ == "__main__":

    num1 = LinkedList()
    a = Node(4)
    a.next = Node(2)
    a.next.next = Node(0)
    num1.head = a

    num2 = LinkedList()
    a = Node(1)
    a.next = Node(2)
    a.next.next = Node(3)
    a.next.next.next = Node(8)
    num2.head = a

    sum = sum_list(num1,num2)

    num1.print()
    num2.print()
    sum.print()
    print()
    print()


    num1 = LinkedList()
    a = Node(1)
    a.next = Node(2)
    num1.head = a

    num2 = LinkedList()
    a = Node(8)
    a.next = Node(8)
    num2.head = a

    sum = sum_list(num1,num2)

    num1.print()
    num2.print()
    sum.print()
    print()
    print()

    sentence = LinkedList()              # test reverse sentence
    a = Node("I")
    b = Node(" ")
    c = Node("a")
    d = Node("t")
    f = Node("e")
    g = Node(" ")
    h = Node("o")
    i = Node("n")
    j = Node("e")


    a.next = b
    b.next = c
    c.next = d
    d.next = f
    f.next = g
    g.next = h
    h.next = i
    i.next = j

    sentence.head = a
    sentence.print()
    print("reverse sentence is:")
    me = rev_sentence(sentence)

    me.print()
    print()
    print()


    a = Node("I")
    b = Node(" ")
    c = Node("l")
    d = Node("o")
    f = Node("v")
    g = Node("e ")
    h = Node(" ")
    i = Node("G")
    j = Node("e")
    k = Node("e")
    l = Node("k")
    m = Node("s")
    n = Node(" ")
    o = Node("f")
    p = Node("o")
    q = Node("r")
    r = Node(" ")
    t = Node("G")
    u = Node("e")
    v = Node("e")
    w = Node("k")
    x = Node("s")
    a.next = b
    b.next = c
    c.next = d
    d.next = f
    f.next = g
    g.next = h
    h.next = i
    i.next = j
    j.next = k
    k.next = l
    l.next = m
    m.next = n
    n.next = o
    o.next = p
    p.next = q
    q.next = r
    r.next = t
    t.next = u
    u.next = v
    v.next = w
    w.next = x


    sentence.head = a
    sentence.print()

    me = rev_sentence(sentence)
    print("reverse sentence is:")
    me.print()
