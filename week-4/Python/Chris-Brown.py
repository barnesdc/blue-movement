#!/usr/bin/env python3

#import regex for the first prompt
import re

#Initialize Node class to create LinkedList Datatype
class Node:

    def __init__(self, data, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev



class LinkedList:

    def __init__(self):
        self.head = None

    def addNode(self, new_data):

        #create Node to be added
        new = Node(data = new_data)

        if self.head is None:
            self.head = new
            self.prev = None
            return

        #move the pointer to the last Node
        else:
            last = self.head
            while (last.next != None):
                last = last.next

        #link the node to the end of the list
        last.next = new
        new.prev = last


    #function to print list
    def printList(self):
        #set temp to the start of the list
        temp = self.head

        #while temp.next points to something
        while (temp.next):
            print(temp.data, end=('->'))

            #set temp to the next Node
            temp = temp.next

        #print the last Node
        print(temp.data, end=('-> NULL'))

def printArray(arr):

    arr.reverse()

    for i in arr:
        i.printList()



#create regex functions to get numbers and letters
def getNumbers(str):

    array = re.findall(r'[0-9]',str)

    return int(''.join(array))

def getLetters(str):
    return str.split()

def getLists(str):

    array = getLetters(str)
    llarray = list()

    for each_split in array:
        ll = LinkedList()
        for ch in each_split:
            if ch.isalpha():
                ll.addNode(ch)
        llarray.append(ll)

    return llarray

def main():

    L1 = '5 -> 6 -> NULL'
    L2 = '8 -> 4 -> 2 -> NULL'
    L3 = 'I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->NULL'
    L4 = 'C->a->r->s-> ->a->r->e-> ->c->o->o->l->NULL'
    num1 = getNumbers(L1)
    num2 = getNumbers(L2)
    sum = num1 + num2

    sumlist = LinkedList()

    for ch in str(sum):
        sumlist.addNode(ch)

    sumlist.printList()
    #arr = getLists(L3[:-4])
    #arr4 = getLists(L4[:-4])
    #printArray(arr)
    #print()
    #printArray(arr4)

if __name__ == '__main__':
    main()
