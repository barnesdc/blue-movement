 """
 This class defines the node object for linked list
 """
 class node:  
    def __init__(self,data):
        self.data = data # Data Assigned
        self.next = None # Next set to null

# adding nodes LIFO
"""
Creating a LIFO linked list
(new values added as the head)
"""
def insert(newNodeData, head):
    newNode = node(newNodeData)
    newNode.next = head
    head = newNode
    return head

"""
Given a linked list head, this function prints
the data in each node
"""
def display(head):
    while(head != None):
        print(head.data, end=" ")
        head = head.next

"""
Given an array or list, this function puts the 
contents of the array or list into a linked list
"""
def createLinkedList(array):
    length = len(array)
    head = None
    for i in range(0,length):
        head = insert(array[i],head)
    return head

"""
Given a LIFO linked list in which all data are
numbers this converts the list into a number
"""
def list2Int(head):
    ptr = head
    output = 0
    i = 0
    while(ptr != None):
        output = output + ptr.data * 10**i
        i = i + 1
        ptr = ptr.next
    return output

"""
This function runs prompt one given two lists
"""
def promptOne(L1,L2):
    N1 = list2Int(L1)
    N2 = list2Int(L2)
    answer = str(N1 + N2)
    answerFlip = answer[4::-1]
    answerList = createLinkedList(answerFlip)
    display(answerList)

"""
This function runs prompt two given one list
""" 
def promptTwo(L3):
    display(L3)    
    
if __name__ == '__main__':
    A1 = [5,6,3]
    A2 = [8,4,2]
    A3 = "hello yall"

    # create linked Lists
    L1 = createLinkedList(A1)
    L2 = createLinkedList(A2)
    L3 = createLinkedList(A3)

    # Run Prompts
    promptOne(L1,L2)
    print()
    promptTwo(L3)

    