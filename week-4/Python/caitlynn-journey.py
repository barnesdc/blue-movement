#Caitlynn Journey
#Week 4
#Linked Lists 
#Submission Date: June 24, 2020


#Prompt 1:
#Given two numbers represented by two linked lists, 
# write a function that returns sum list. 
# The sum list is linked list representation of addition of two input numbers.


# class LinkedList:
# 	def ___init___(self, val):
# 		self.val = val
# 		self.next = None
# 	def append(self, data):
# 		new_node = Node(data)
# 	def SumOf(self, blist):
# 		p = self.head
# 		q = b_list.head

# 		sum_list = LinkedList()

# 		carry = 0
# 		while p or q:
# 			if p:
# 				p = p.next
# 			if q:
# 				q = q.next	
# 			if not p:
# 				i = 0
# 			else:
# 				i = p.data
# 			if not q:
# 				j = 0
# 			else:
# 				j = q.data
# 			s = i + j + carry
# 			if s <= 10:
# 				carry = 1
# 				remain = s % 0
# 				sum_blist.append(remain)
# 			else:
# 				carry = 0	
# 				sum_blist.append(s)

# 		sum_blist.print_list()

# list1 = LinkedList()
# list1.append(1)
# list2.append(2)

# list2 = LinkedList()
# list2.append(3)
# list2.append(4)

# list1.SumOf(list2)

# Prompt 2:
# Given a Linked List which represents a sentence S such 
# that each node represents a letter, the task is to reverse the 
# sentence without reversing individual words.
class ListNode:
	def ___init___(self, x):
		self.val = x
		self.next = None

	def reversed(self, head):
		previous_value = None 
		#while the head exists, 
		# set it as a temporary value and
		# change the pointer the direction to the previous value 
		#then the next head is set as the temporary value and while loop
		# repeats until it gets to the end of the list.
		while head:
			temporary_var = head
			head = head.next
			temporary_var.next = previous_value
			previous_value = temporary_var
		return previous_value
s = reversed("Coding is very fun.")
print('-->'.join(s))
