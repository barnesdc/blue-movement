class LinkedList:
    def sum_linked_lists(self, l1, l2):
        carry = 0
        root = n = ListNode(0)
        while l1 or l2 or carry:
            v1 = v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            carry, val = divmod(v1+v2+carry, 10)
            n.next = ListNode(val)
            n = n.next
        return root.next

class Node: 

        def __init__(self, data):    
                self.data = data         
                self.next = None          

class LinkedList: 

    def __init__(self):
        self.head = None      

    def append(self, new_value): 
        new_node = Node(new_value)   
        if self.head is None:  
            self.head = new_node
            return
        tmp = self.head
        while tmp.next is not None:
            tmp = tmp.next
        tmp.next = new_node

    def print_list(self): 
        temp = self.head 
        while(temp): 
            print (temp.data+"->", end="") 
            temp = temp.next
        print("NULL")

    def print_srting(self): 
        temp = self.head 
        while(temp): 
            print (temp.data, end="") 
            temp = temp.next

    def reverse_sent(self):
        if self.head is None:  
            return
        word_sp = self.head          
        sent_end = Node(None)       
        sent_start = Node(None)     
        temp = self.head
        while temp is not None and temp.data != ' ':
            sent_end = temp
            temp = temp.next
        if temp is None:
            return
        while temp is not None:
            tmp_next = temp.next
            temp.next = word_sp
            word_sp = temp 
            prev = Node(None)
            temp = tmp_next 
            sent_start = temp
            while temp is not None and temp.data != ' ':
                prev = temp
                temp = temp.next
            prev.next = word_sp
            word_sp = sent_start
        self.head = sent_start        
        sent_end.next = None


