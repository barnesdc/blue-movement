# A simple Python program for traversal of a linked list 
# Node class 
class Node: 
    # Function to initialise the node object 
    def __init__(self, data): 
        self.data = data  # Assign data 
        self.next = None  # Initialize next as null 
# Linked List class contains a Node object 
class LinkedList: 
    # Function to initialize head 
    def __init__(self): 
        self.head = None



##################
## Main Methods ##
##################
def asgn3(*args):
    l1, l2, loutput = None, None, None
    if len(args) == 2:
        l1, l2 = args[0], args[1]
        loutput = addTwoLists(l1, l2)
    else:
        l1 = args[0]
        loutput = reverseListByWords(l1)
    printList(loutput)
    return loutput

def addTwoLists(l1, l2):
    ## Convert these to integers
    l1int, l2int = listToInt(l1), listToInt(l2)
    addedList = l1int + l2int
    return intToList(addedList)

def reverseListByWords(l):
    lString = listToStr(l)
    lArr = list(lString.split(' '))
    lArrRev = lArr[::-1]
    lStrRev = ' '.join(lArrRev)
    lArrRevMerge = list(lStrRev)
    return arrToList(lArrRevMerge, 'str')

#######################
## From List Methods ##
#######################
def listToInt(l):
    return int(listToStr(l))

def listToStr(l):
    lString = ''
    currNode = l.head
    while (currNode.next != None):
        lString += str(currNode.data)
        currNode = currNode.next
    lString += str(currNode.data)
    return lString

#####################
## To List Methods ##
#####################
def strToList(string):
    return arrToList(string, 'str')

def intToList(i):
    iString = str(i)
    iArr= list(iString)
    return arrToList(iArr, 'int')

def arrToList(arr, operationType):
    arrList = LinkedList()
    if operationType == 'int':
        arrList.head = Node(int(arr[0]))
    elif operationType == 'str':
        arrList.head = Node(str(arr[0]))
    currNode = arrList.head
    for data in arr[1:]:
        if operationType == 'int':
            currNode.next = Node(int(data))
        elif operationType == 'str':
            currNode.next = Node(str(data))
        currNode = currNode.next
    return arrList

#############
## Printer ##
#############
def printList(l):
    currNode = l.head
    while (currNode.next != None):
        print(currNode.data)
        currNode = currNode.next
    print(currNode.data)




def main():
    arr1, arr2 = [1, 2, 3, 4], [1, 2, 3, 4]
    intl1, intl2 = arrToList(arr1, 'int'), arrToList(arr2, 'int')

    string = 'my name is jorge canedo'
    strl1 = strToList(string)

    asgn3(intl1, intl2)
    print()
    asgn3(strl1)



if __name__ == '__main__':
    main()
    
  