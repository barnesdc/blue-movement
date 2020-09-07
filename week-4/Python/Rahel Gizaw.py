"""
    Prompt 1
"""
class Node:
  def __init__(self, data): 
    self.data = data 
    self.next = None

class LinkedList: 
  def __init__(self): 
    self.head = None

	# Function to insert a new node at the beginning 
  def push(self, new_data): 
    new_node = Node(new_data) 
    new_node.next = self.head 
    self.head = new_node 

  def addTwoLists(self, first, second): 
    prev = None
    temp = None
    carry = 0

		# While both list exists 
    while(first is not None or second is not None): 
      fdata = 0 if first is None else first.data 
      sdata = 0 if second is None else second.data 
      Sum = carry + fdata + sdata 
      carry = 1 if Sum >= 10 else 0
      Sum = Sum if Sum < 10 else Sum % 10
      temp = Node(Sum) 
      if self.head is None: 
        self.head = temp 
      else : 
        prev.next = temp 

          # Set prev for next insertion 
      prev = temp 

      # Move first and second pointers to next nodes 
      if first is not None: 
        first = first.next
      if second is not None: 
        second = second.next

      if carry > 0: 
        temp.next = Node(carry) 

	# Utility function to print the linked LinkedList 
  def printList(self):
    lst = []
    temp = self.head 
    while(temp): 
      lst.append(temp.data) 
      temp = temp.next
    lst.reverse()
    for i in lst:
      print(i)

# Driver program to test above function 
first = LinkedList()
second = LinkedList() 

# Create the first list 
first.push(5),first.push(6),first.push(3) 
print ("The First List = >> ") 
first.printList() 

# Create the second list 
second.push(8), second.push(4), second.push(2) 
print ("\nThe Second List =>> ") 
second.printList() 

# Adding the two lists and see the results  
res = LinkedList() 
res.addTwoLists(first.head, second.head) 
print( "\nThe Results of the two added lists will be") 
res.printList() 


"""
    Prompt 2
"""

class Node:
  def __init__(self, data): 
    self.data = data 
    self.next = None


def createLinkedList(s):
  header = None
  temp = None
  for  i in s:
    node = Node(i)
    if(header == None):
      header = node
      temp = header
    else:
      temp.next = node
      temp = temp.next
  return header

def reverse(header):
  if(header==None):
    return header
  wrdStrtPos = None
  endOfSent = None
  sentStrtPos = None

  wrdStrtPos=header
  while(header!= None and header.data != " "):
    endOfSent = header
    header = header.next


  if(header == None):
    header = wrdStrtPos
    return header

  while(header != None):
    temp = header.next
    header.next = wrdStrtPos
    wrdStrtPos = header
    header = temp
    prev = None
    sentStrtPos = header

    while(header != None and header.data != ' '):
      prev = header
      header = header.next
    prev.next = wrdStrtPos

    wrdStrtPos=sentStrtPos

    if(header==None):
      break
  header = sentStrtPos
  endOfSent.next = None
  return header

def printList(header):
  temp = header
  newSent = ""
  while(temp!=None):
    newSent += temp.data
    temp = temp.next
  print(newSent)
  
s = "I love geeks for geeks"
header = createLinkedList(s)
print("Old sentence\n", s)
header = reverse(header)
print("New sentence",)
printList(header)



















