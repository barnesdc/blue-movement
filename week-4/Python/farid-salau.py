# problem 1


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        temp = self
        l = []
        while temp:
            l.append(str(temp.val))
            temp = temp.next
        return " ".join(l)


class LinkedList:
    def __init__(self):
        self.head = None

    def addNode(self, data):
        node = ListNode(data)
        node.next = self.head
        self.head = node

    def addTwoNumbers(self, l1, l2):
        carry = 0
        res = n = ListNode(0)
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            carry, val = divmod(carry, 10)
            n.next = n = ListNode(val)
        return res.next

    def reverse(self, l):
        cur = l
        prev = None

        while cur:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp

        return prev


l1 = LinkedList()
l2 = LinkedList()

l1.addNode(1)
l1.addNode(2)
l1.addNode(3)
l2.addNode(4)
l2.addNode(5)
l2.addNode(6)

print(LinkedList().addTwoNumbers(l1.head, l2.head))

###########################     END PROBLEM ONE    ##############################

# problem 2
