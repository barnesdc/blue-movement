import asyncio
# A single node of a singly linked list
class Node:
  # constructor
  def __init__(self, data = None, next=None): 
    self.data = data
    self.next = next
  def __repr__(self):
    return self.data
  def __str__(self):
    return str(self.data)

# A Linked List class with a single head node
class LinkedList:
  def __init__(self):  
    self.head = None
  
  # insertion method for the linked list
  def insert(self, data):
    newNode = Node(data)
    if(self.head):
      current = self.head
      while(current.next):
        current = current.next
      current.next = newNode
    else:
      self.head = newNode
  
  # Function to print the data 
  # present in all the nodes 
  def printList(self):
        n = self.head
        while n:
            print(str(n))
            n = n.next
  
"""
Question 1:
Given two numbers represented by two linked lists, 
write a function that returns sum list. 

The sum list is linked list representation of addition of two input numbers.
"""
list1 = LinkedList()
list1.insert(5)
list1.insert(6)
list1.insert(3)

list2 = LinkedList()
list2.insert(8)
list2.insert(4)
list2.insert(2)

#add each number to two stacks
stack1 = []
current = list1.head

while current is not None:
    stack1.append(current.data)
    current = current.next

stack2 = []
current = list2.head
while current is not None:
    stack2.append(current.data)
    current = current.next

carry = 0
resultstack = []
#add going through the stack by popping off the top
while stack1 and stack2:
    num1 = stack1.pop()
    num2 = stack2.pop()
    sum = num1+num2
    if carry > 0:
        sum += 1
    if sum >= 10:
        sum = sum -10
        carry = 1
    
    resultstack.append(sum)

while stack1:
    if carry:
        resultstack.append(carry)
        carry = 0
    resultstack.append(stack1.pop())
while stack2:
    if carry:
        resultstack.append(carry)
        carry = 0
    resultstack.append(stack1.pop())
if carry:
        resultstack.append(carry)
        carry = 0
        
#add new stack as a linked list
result = LinkedList()
while resultstack:
    result.insert(resultstack.pop())

# result.printList()

"""
Question 1:
Given two numbers represented by two linked lists, 
write a function that returns sum list. 

The sum list is linked list representation of addition of two input numbers.
"""
list1 = LinkedList()
list1.insert("I")
list1.insert(" ")
list1.insert("l")
list1.insert("o")
list1.insert("v")
list1.insert("e")
list1.insert(" ")
list1.insert("G")
list1.insert("e")
list1.insert("e")
list1.insert("k")
list1.insert("s")
list1.insert(" ")
list1.insert("f")
list1.insert("o")
list1.insert("r")
list1.insert(" ")
list1.insert("G")
list1.insert("e")
list1.insert("e")
list1.insert("k")
list1.insert("s")

q = asyncio.Queue()
stack = []
result = LinkedList()
current = list1.head
#queue for the letters, stack for the words
while current.next is not None:
    if current.data is " ":
        stack.append(q)
        q = asyncio.Queue()
    else:
        q.put_nowait(current.data)
    current = current.next

if current is not None:
    q.put_nowait(current.data)
if not q.empty():
    stack.append(q)

while stack:
    q = stack.pop()
    while not q.empty():
        result.insert(q.get_nowait())
    result.insert(" ")

result.printList()