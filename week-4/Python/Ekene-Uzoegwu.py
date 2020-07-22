import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# linkedList subclasscd
#Prompt   - Example: 
#   > Input:  I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->NULL
#   > Output: G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->NULL

class LinkedList:
    def __init__(self):
        self.head = None

    def print_list(self):
        cur_node = self.head
        while cur_node:
            print(cur_node.data,end= ' ')
            cur_node = cur_node.next
    

    # append function
    def append(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node
    
    # reverse function
    def sentence_reverse(self,sentence):
        previous = None
        current = sentence.head
        After = current.next

        while current:
            current.next = previous # reverse the link list
            previous = current
            current = After 
            if After:
                After = After.next
        
        sentence.head = previous


    def two_list_summation(self, List_list):
        first_list_num = self.head  
        second_list_num = List_list.head
        
        # stores the sum of p and  q
        sum_of_two_list = LinkedList()

        carry = 0
        while first_list_num or second_list_num:
            if not first_list_num:
                x = 0
            else:
                x = first_list_num.data
            if not second_list_num:
                y = 0 
            else:
                y = second_list_num.data
            sum = x + y + carry
            if sum >= 10:
                carry = 1
                # working with remainder
                remainder = sum % 10
                sum_of_two_list.append(remainder)
            # a case without remainder
            else:
                carry = 0
                sum_of_two_list.append(sum)
            if first_list_num:
                first_list_num = first_list_num.next
            if second_list_num:
                second_list_num = second_list_num.next
        sum_of_two_list.print_list()




List_list1 = LinkedList()
List_list1.append(5)
List_list1.append(6)
List_list1.append(3)

List_list2 = LinkedList()
List_list2.append(8)
List_list2.append(4)
List_list2.append(2)

print(563 + 842)
# List_list1.two_list_summation(List_list2)


print(f"Reverse string function is below")

ReverseSentence = LinkedList()
ReverseSentence.append("I Love ")
ReverseSentence.append("Geeks")
ReverseSentence.append("for")
ReverseSentence.append("Geeks")

print(f"before reverse")
ReverseSentence.print_list()

print("After reversing")

ReverseSentence.sentence_reverse(ReverseSentence)
ReverseSentence.print_list()

