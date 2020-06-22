class node:
    # initialization of node object
    def __init__(self,data):
        self.data = data # Data Assigned
        self.next = None # Next set to null

# adding nodes LIFO
def insert(newNodeData, head):
    newNode = node(newNodeData)
    newNode.next = head
    head = newNode
    return head

def display(head):
    while(head != None):
        print(head.data, end=" ")
        head = head.next

def createLinkedList(array):
    length = len(array)
    head = None
    for i in range(0,length):
        head = insert(array[i],head)
    return head

def list2Int(head):
    ptr = head
    output = 0
    i = 0
    while(ptr != None):
        output = output + ptr.data * 10**i
        i = i + 1
        ptr = ptr.next
    return output

def promptOne(L1,L2):
    N1 = list2Int(L1)
    N2 = list2Int(L2)
    answer = str(N1 + N2)
    answerFlip = answer[4::-1]
    answerList = createLinkedList(answerFlip)
    display(answerList)

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

    promptOne(L1,L2)
    print()
    promptTwo(L3)

    