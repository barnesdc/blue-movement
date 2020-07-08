# -*- coding: utf-8 -*-
"""
Created on Tue Jun 23 20:27:11 2020

@author: andre
"""

class Node:
    def __init__(self, data = None, arrow = None):
        self.data = data
        self.arrow = arrow
        
    def __str__(self):
        return str(self.data)
        
class linked_list:
    def __init__(self):
        self.head = None
        
    def insert(self, data):
        baby_node = Node(data)
        if (self.head):
            current = self.head
            while (current.arrow):
                current = current.arrow
            current.arrow = baby_node
        else:
            self.head = baby_node
            
    def print_list(self):
        current = self.head
        while (current):
            print(str(current))
            current = current.arrow
    def length(self):
        count = 0
        node = self.head
        while node != None:
            count += 1
            node = node.arrow
        return count
    def equal(self, L2):
        node = self.head
        node2 = L2.head
        answer = True
        if self.length() == L2.length():
            while node != None and answer == True:
                equal = node.data == node2.data
                if not equal:
                    answer = False
                node = node.arrow
                node2 = node2.arrow
            return answer
        else: 
            return False
        
        
def sum_2_lists(list1, list2):
    nums1 = []
    nums2 = []
    node = list1.head
    while node != None:
        nums1.append(node.data)
        node = node.arrow
    node = list2.head
    while node != None:
        nums2.append(node.data)
        node = node.arrow
    carry = 0
    result = []
    while nums1 != [] and nums2 != []:
        add = nums1.pop() + nums2.pop()
        add += carry
        carry = 0
        if add > 9:
            carry = 1
            add = add - 10
        result.append(add)
    while nums1 != []:
        if carry > 0:
            result.append(nums1.pop() + carry)
            carry = 0
        else:
            result.append(nums1.pop())
    while nums2 != []:
        if carry > 0:
            result.append(nums2.pop() + carry)
            carry = 0
        else:
            result.append(nums2.pop())
    answer = linked_list()
    if carry > 0:
        result.append(carry)
    while result != []:
        answer.insert(result.pop())
    return answer


def join_lists(L1, L2):
    node = L2.head
    while node!= None:
        L1.insert(node.data)
        node = node.arrow

def reverse_sentence(linked_lis):
    node = linked_lis.head
    #stack to reverse word order
    reverse = []
    #word linked_list
    word = linked_list()
    count = 0
    while node != None:
        if node.data == " ":
            reverse.append(word)
            word = linked_list()
            count += 1
        else:
            word.insert(node.data)
        node = node.arrow
    
    #reverse.append(word_queue)
    reverse.append(word)
    answer = reverse.pop()
    while reverse != []:
        if count > 0:
            answer.insert(" ")
        join_lists(answer, reverse.pop())
        count -= 1
    return answer
            
def string_to_ll(string):
    ll = linked_list()
    for index in range(len(string)):
        ll.insert(string[index])
    return ll
def nums_to_ll(num_list):
    ll = linked_list()
    for num in num_list:
        ll.insert(num)
    return ll

        
def test_string_to_ll():
    first_case = linked_list()
    first_case.insert("I")
    assert string_to_ll("I").head.data == first_case.head.data
    first_case.insert(" ")
    first_case.insert("L")
    answer = string_to_ll("I L")
    assert first_case.equal(answer)
    print("string_to_ll function works")
    
def test_sum_2_lists():

    L1 = nums_to_ll([5, 6, 3])

    L2 = nums_to_ll([8, 4, 2])
    
    L3 = nums_to_ll([0])
    L4 = nums_to_ll([1])
    L5 = nums_to_ll([2])

    answer1 = nums_to_ll([1, 4, 0, 5])
    answer2 = nums_to_ll([0])
    answer3 = nums_to_ll([3])

    first_case = sum_2_lists(L1,L2)
    second_case = sum_2_lists(L3, L3)
    third_case = sum_2_lists(L4, L5)
    assert first_case.equal(answer1)
    assert second_case.equal(answer2)
    assert third_case.equal(answer3)
    print("sum_2_lists function works")



def test_reverse_sentence():
    L1 = string_to_ll("I love Geeks for Geeks")
    answer1 = string_to_ll("Geeks for Geeks love I")
    
    L2 = string_to_ll("")
    L3 = string_to_ll("Hai")

    first_case = reverse_sentence(L1)
    assert first_case.equal(answer1)
    assert reverse_sentence(L2).equal(L2)
    assert reverse_sentence(L3).equal(L3)
    print("reverse_sentence function works")
    
test_string_to_ll()
test_sum_2_lists()
test_reverse_sentence()
            
                
                
                
        