#class method to intialize from Geeks for Geeks
class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None 

    def printList(self):
        printval = self.head
        while(printval):
            print(printval.data)
            printval = printval.next
    
    #adds to the end of list         
    def append(self, item):
        temp = Node(item)
        if (self.head == None):
            self.head = temp
        else:
            ptr = self.head
            while (ptr.next != None):
                ptr = ptr.next
            ptr.next = temp
            self.tail = ptr.next

    #adds to the beginning        
    def prepend(self, item):
        temp = Node(item)
        temp.next = self.head
        self.head = temp 
    
    def insertafter(self, ptr, item):
        temp = Node(item)
        after = ptr.next
        ptr.next = temp
        temp.next = after
        return temp
      
    #removed from end
    def pop(self):
        if(self.head != None):
            ptr = self.head
            temp = self.head
            while(ptr.next != None):
                temp = ptr
                ptr = ptr.next 
            temp.next = None
            self.tail = temp
            return ptr.data
        else:
            temp = self.head
            self.head = None
            self.tail = None

    #finds length of linked list
    def lgth(self):
        len = 0
        if(self.head != None):
            len = 1
            ptr = self.head
            while (ptr.next != None):
                len += 1 
                ptr = ptr.next
            return len      


def sumlst(lst1, lst2):
    #gets length of lists
    len1 = lst1.lgth()
    len2 = lst2.lgth()
    lgth = 0
    val1 = 0
    val2 = 0 
    carry = 0
    #checks if length is shorter and inserts 0 at the front if shorter 
    if(len1 < len2):
        for i in range(0, len2-len1):
            lst1.prepend(0)
        lgth = len2    
    elif(len1 > len2):
        for i in range(0, len1-len2):
            lst2.prepend(0)
        lgth = len1
    else:
        lgth = len1
    #total list representation     
    totlist = LinkedList()
    #loops through the lists from the back and adds values and saves carry
    for i in range(0,lgth):
        val1 = lst1.pop()
        val2 = lst2.pop()
        sm = (val1 + val2) % 10
        totlist.prepend(sm + carry)
        carry = (val1 + val2) // 10
        #case if an extra digit needs to be added to the front
        if(carry == 1 and i == lgth-1):
            totlist.prepend(carry)
    return totlist        

def revsent(lst):
    revsnct = LinkedList()
    ptr = lst.head
    lenlst = lst.lgth()
    spacebefore = False
    prev = None  
    for i in range(0, lenlst):
        if (i == 0):
            revsnct.append(ptr.data)
            prev = revsnct.head
        elif(ptr.data == " "):
            revsnct.prepend(ptr.data)
            spacebefore = True
            prev = revsnct.head
        else:
            if(spacebefore == False):
                prev = revsnct.insertafter(prev, ptr.data)
            else:
                revsnct.prepend(ptr.data)
                prev = revsnct.head
                spacebefore = False 
        ptr = ptr.next
    return revsnct

def fillList(str):
    lst = LinkedList()
    for i in str:
        lst.append(i)
    return lst

def main():
    lst1 = LinkedList()
    lst2 = LinkedList()
    lst2.head = Node(8)
    lst1.head = Node(5)
    lst1.append(6)
    lst1.append(3)
    lst2.append(4)
    lst2.append(2)
    smlst = sumlst(lst1, lst2)
    smlst.printList()

    #lst3 = fillList("I love Geeks for Geeks")
    #rs = revsent(lst3)
    #rs.printList()

if __name__ == "__main__":
    main()                      