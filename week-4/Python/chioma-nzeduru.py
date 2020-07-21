
class Node:
    def __init__(self, val):
        self.val = val
        self.nextNode = None


class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, new_val):
        new_node = Node(new_val)
        new_node.nextNode = self.head
        self.head = new_node

    # Sum of two lists
    # Numbers are removed from the stacks(lists) and added together.
    # If the sum is equal to or greater than 10, the carry variable
    # carries the number in the tens place and adds it to the next
    # sum.
    # Time complexity is O(n^2).

    def sumlist(self, one, two):
        new_list = LinkedList()
        arr = []
        carry = 0
        first = one.head
        second = two.head
        while first or second:
            if first and second:
                if (first.val + second.val) < 10:
                    arr.append(first.val + second.val + carry)
                    carry = 0
                else:
                    arr.append((first.val + second.val + carry) % 10)
                    carry = 1

            elif first:
                arr.append(first.val + carry)
                carry = 0

            else:
                arr.append(second.val + carry)
                carry = 0

            if first:
                first = first.nextNode
            if second:
                second = second.nextNode

        if carry != 0:
            arr.append(carry)

        [new_list.push(i) for i in arr[::-1]]

        return new_list

    # Reverse list
    # The idea for this problem is to push the sentence onto a stack (linked list) and then remove each word from the
    # stack, reverse it (in an array) and then push it onto another stack.
    # Time complexity is O(n), I believe.

    def reverse(self):
        new_list = LinkedList()
        arr = []
        temp = self.head
        while temp:
            arr.append(temp.val)
            if temp.val == ' ':
                [new_list.push(i) for i in arr[::-1]]
                arr = []
            if not temp.nextNode:
                [new_list.push(i) for i in arr[::-1]]

            temp = temp.nextNode

        return new_list

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.val)
            temp = temp.nextNode
        print('\n')


S = LinkedList()
S.push('s')
S.push('k')
S.push('e')
S.push('e')
S.push('G')
S.push(' ')
S.push('r')
S.push('o')
S.push('f')
S.push(' ')
S.push('s')
S.push('k')
S.push('e')
S.push('e')
S.push('G')
S.push(' ')
S.push('e')
S.push('v')
S.push('o')
S.push('l')
S.push(' ')
S.push('I')

S.print_list() # I love Geeks for Geeks
S = S.reverse()
S.print_list() # Geeks for Geeks I love

#C = LinkedList()
#C.push('l')
#C.push('o')
#C.push('o')
#C.push('c')
#C.push(' ')
#C.push('e')
#C.push('r')
#C.push('a')
#C.push(' ')
#C.push('s')
#C.push('r')
#C.push('a')
#C.push('C')

#C.print_list() # Cars are cool
#C = C.reverse()
#C.print_list() # cool are Cars

L1 = LinkedList()
L2 = LinkedList()

L1.push(3)
L1.push(6)
L1.push(5)

L2.push(5)
L2.push(0)
L2.push(0)


L3 = LinkedList()
L3 = L3.sumlist(L1, L2)

L1.print_list() # 563
L2.print_list() # 005
L3.print_list() # 568


#L1 = LinkedList()
#L2 = LinkedList()

#L1.push(3)
#L1.push(6)
#L1.push(5)

#L2.push(8)
#L2.push(4)
#L2.push(2)


#L3 = LinkedList()
#L3 = L3.sumlist(L1, L2)

#L1.print_list() # 563
#L2.print_list() # 842
#L3.print_list() # 1405



#L1 = LinkedList()
#L2 = LinkedList()

#L1.push(5)
#L1.push(6)
#L1.push(3)

#L2.push(8)
#L2.push(5)
#L2.push(0)


#L3 = LinkedList()
#L3 = L3.sumlist(L1, L2)

#L1.print_list() # 563
#L2.print_list() # 85
#L3.print_list() # 648
