# Austen Williams 
# Week 4 Prompts 1 & 2

"""
1)  Given two numbers represented by two linked lists, write a function that 
    returns sum list. The sum list is linked list representation of addition 
    of two input numbers.
    
    - Example: Input:
        
    L1 = 5 -> 6 -> 3 -> NULL
    L2 = 8 -> 4 -> 2 -> NULL
    
  Output: 1 -> 4 -> 0 -> 5 -> NULL
  
2) Given a Linked List which represents a sentence S such that each node 
   represents a letter, the task is to reverse the sentence without reversing 
   individual words.
  - Example: 
  > Input:  I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->NULL
  > Output: G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->NULL
  
  
"""



class Node:
    'Node class that holds data with pointer to previous and next node'
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
        

class LinkedList:
    'Doublylinked List Containing refrences to first and last nodes'
    
    def __init__(self):
        'initializes head and last nodes of the linked list'
        self.head = None
        self.last = None
        self.N = 0
        
    def insert(self, data):
        'instance method for inserting new Node'
        new_node = Node(data)
        if self.N == 0:
            self.head = new_node
            self.last = new_node
            self.N += 1
            return
        else:
            self.last.next = new_node
            new_node.prev = self.last
            self.last = new_node
            self.N += 1
            return
    
    def insertEnd(self, data):
        'instance method for inserting at the end of the linked list'
        new_node = Node(data)
        if self.last == None:
            self.head = new_node
            self.last = new_node
            self.N += 1
        else:
            i = self.last
            while i.prev != None:
                i = i.prev
            i.prev= new_node
            new_node.next = i
            self.head = new_node
            self.N += 1
    
    def printList(self):
        'prints linked list'
        nodes = self.head
        while nodes != None:
            print(f'{nodes.data}', end= ' --> ')
            nodes = nodes.next
        print('None')
        
        
        
class LinkListOperator:
    'Class that performs Prompt operations on Linked Lists'
             
    def sumLinks(self, L1, L2):
        'sums two linked lists and returns sum as a linked list'
        if L1.N == L2.N:
            return self.sumEven(L1, L2)
        else:
            return self.sumOdd(L1,L2)


    
    def sumOdd(self, L1, L2):
        'adds two linked lists of uneven length and returns sum as Linked list'
        new_list = LinkedList()
        if L1.N > L2.N:
            max_list = L1.last
            min_list = L2.last
        else:
            max_list = L2.last
            min_list = L1.last
        remain = 0
        while min_list != None:
            data = min_list.data + max_list.data + remain
            if data > 9:
                new_list.insertEnd(data % 10)
                remain = data // 10
            else:
                new_list.insertEnd(data)
                remain = 0
            min_list = min_list.prev
            max_list = max_list.prev
            
        while max_list != None:
            data = max_list.data + remain
            if data > 9:
                new_list.insertEnd(data % 10)
                remain = data // 10
            else:
                new_list.insertEnd(data)
                remain = 0
            max_list = max_list.prev
        if remain > 0:
            new_list.insertEnd(remain)
        return new_list
            
    
    def sumEven(self, L1, L2):
        'adds two linked lists of even in length and returns sum as linked list'
        list1 = L1.last
        list2 = L2.last
        new_list = LinkedList()
        remain = 0
        while list1 != None and list2 != None:
            data = list1.data + list2.data + remain
            if data > 9:
                new_list.insertEnd(data%10)
                remain = data // 10
            else:
                new_list.insertEnd(data)
                remain = 0
            list1 = list1.prev
            list2 = list2.prev
        if remain > 0:
            new_list.insertEnd(remain)
        return new_list

    
    def reverseSentence(self, S):
        'Reverses sentence in the form of a Linked list'
        new_list = LinkedList()
        temp_lst = list()
        letter = S.last
        while letter != None:
            if letter.data == " ":
                while len(temp_lst) > 0:
                    new_list.insert(temp_lst.pop())
                new_list.insert(" ")
                letter = letter.prev
            else:
                temp_lst.append(letter.data)
                letter = letter.prev
        while len(temp_lst) > 0:
                    new_list.insert(temp_lst.pop())
        return new_list
    

if __name__ == "__main__":
    
    def testSum(link_sum, answer):
        test = link_sum.head
        ans = answer.head
        while test != None and ans != None:
            if test.data != ans.data:
                print("Unsuccessful")
                return
            test = test.next
            ans = ans.next
        print("Success")
        
        
    def testReverse(sent, answ):
        senten = sent.head
        ans = answ.head
        
        while senten != None and ans != None:
            if senten.data != ans.data:
                print("Unsuccessful")
                return
            senten = senten.next
            ans = ans.next
        print("Success")
    
    def test1():
        'Test 999 + 1 which equals 1000'
        test = LinkListOperator()
        L1 = LinkedList()
        L1.insert(9)
        L1.insert(9)
        L1.insert(9)
    
        L2 = LinkedList()
        L2.insert(1)
        
        answer = LinkedList()
        answer.insert(1)
        answer.insert(0)
        answer.insert(0)
        answer.insert(0)
        
        link_sum = test.sumLinks(L1, L2)
        testSum(link_sum, answer)
        link_sum.printList()
        answer.printList()
        
    
    def test2():
        'test 563 + 842 which equals 1405'
        test = LinkListOperator()
        L1 = LinkedList()
        L1.insert(5)
        L1.insert(6)
        L1.insert(3)
    
        L2 = LinkedList()
        L2.insert(8)
        L2.insert(4)
        L2.insert(2)
    
        answer2 = LinkedList()
        answer2.insert(1)
        answer2.insert(4)
        answer2.insert(0)
        answer2.insert(5)
        link_sum = test.sumLinks(L1, L2)
        testSum(link_sum, answer2)
        link_sum.printList()
        answer2.printList()
    
    
    def testSentence():
        'tests reversing sentence function'
        test = LinkListOperator()
        sentence = "I love Geeks for Geeks"
        answSentence = "Geeks for Geeks love I" 
        sentenceList = LinkedList()
        answList = LinkedList()
        for i in sentence:
            sentenceList.insert(i)
        for i in answSentence:
            answList.insert(i)
        
        temp = test.reverseSentence(sentenceList)
        
        testReverse(temp, answList)
        temp.printList()
        answList.printList()
    
    test1()
    test2()
    testSentence()       
            
        
   

