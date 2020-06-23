# Class Node gives each cell in the linked list two values, i.e., nvalue for storing integer and next for storing address of next node
class Node:
    def __init__(self, nvalue=None):
        self. nvalue= nvalue
        self.next= None

# Class LinkList consists of all the functions required to make a linked list
class LinkList:
    def __init__(self):
        self.headvalue= None 
    
    def makelink(f,num):
            f.num=num
            f.digit=1
            while(f.num!=0):
                f.rem=f.num%10
                f.num=f.num//10
            
                if(f.digit==1):
                    move= Node(f.rem)
                    f.headvalue= move
                          
                elif(f.digit%2==0):
                    move1=Node(f.rem)
                    move.next=move1
                    
                elif(f.digit%2!=0):
                    move=Node(f.rem)
                    move1.next=move
                f.digit= f.digit+1
                
    def printlist(self):
        printvalue = self.headvalue
        while printvalue!=None:
            print(printvalue.nvalue,end=' -> ')
            printvalue= printvalue.next
        print('NULL')

# Function to reverse the numbers
def revrs(num):
    rev=0
    while(num!=0):
        rem=num%10
        rev=rev*10+rem
        num=num//10
    return rev

# Main Body
num1= int(input(" Enter the first number: "))
num2= int(input(" Enter the second number: "))
add= num1+num2

# Here we are reversing the numbers because the numbers get again reversed while getting pushed in the linked list.
# So, in order to add the numbers correctly we need to initially reverse them before passing to become linkedlist nodes.
num1= revrs(num1)
num2= revrs(num2)
add= revrs(add)

l1=LinkList()               
l1.makelink(num1)
l1.printlist()

l2=LinkList()
l2.makelink(num2)
l2.printlist()

lsum=LinkList()
lsum.makelink(add)
lsum.printlist()
