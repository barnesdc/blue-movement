class node:
    def __init__(self,data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self,data):
        self.head = node()

    def append(self,data):
        new_node = node(data)
        cur = self.head
        while cur.next!= None:
            cur =cur.next
        cur.next = new_node
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, "-> ", end="")
            temp = temp.next
        print()


def addTwoNumbers(l1,l2):

    cur1 = l1
    cur2 = l2
    list1 = []
    list2 = []
       
    while cur1:
        list1.append(cur1.data)
        cur1 = cur1.next

    while cur2:
        list2.append(cur2.data)
        cur2 = cur2.next
       
       
    list11 = [str(i) for i in list1]
    list22 = [str(i) for i in list2]
       
    num1 = int("".join(list11))
    num2 = int("".join(list22))
    ans = str(num1 + num2)
       
    node = ListNode(ans[0])
    counter = node
       
    for i in range(1, len(ans)):
        new = ListNode(ans[i])
        counter.next = new
        counter = counter.next
           
    return node

l1 = LinkedList()
l2 = LinkedList()

l1.append(5)
l1.append(6)
l1.append(3)
l2.append(8)
l2.append(4)
l2.append(2)

addTwoNumbers(l1,l2).printList()



    
# class ListNode:
#     def __init__(self,x):
#         self.val = x
#         self.next = None
# class Solution:
#     def addSum(self,l1):

#         prev = None
#         cur = self.head
        
#         while cur:
#             next = cur.next
#             cur.next = prev
#             prev = cur
#             cur = next
#             self.head = prev 
#         return cur


