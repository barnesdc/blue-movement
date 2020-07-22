class node: 
    def __init__(self, data= None):
        self.data = data
        self.next = None
    #last exement pointer is set to none

class LinkedList:
    def __init__(self):
        self.head = node()
        #head node = use as place holder for first element

    def append(self, data):
        new_node = node(data)
        curr = self.head
        while curr.next!=None:
            curr = curr.next
        curr.next = new_node

    def size(self):
        curr = self.head
        total = 0
        while curr.next!=None:
            total+=1
            curr = curr.next
        return total

    def display(self):
        elems = []
        cur_node = self.head
        while cur_node.next!=None:
            cur_node = cur_node.next
            elems.append(cur_node.data)
        print(elems)
    
    def get(self, index):
        if index >= self.size():
            print("error")
            return None
        cur_idx = 0
        cur_node = self.head
        while True:
            cur_node = cur_node.next
            if cur_idx == index: return cur_node.data
            cur_idx+=1

    def erase(self, index):
        if index>=self.size():
            print("error")
            return None
        cur_idx =0
        cur_node = self.head
        while True:
            last_node = cur_node
            cur_node = cur_node.next
            if cur_idx == index:
                last_node.next = cur_node.next
                return
            cur_idx+=1
    



my_list = LinkedList()
my_list.display()
my_list.append(1)
my_list.append(2)
my_list.append(3)
my_list.append(4)

my_list.display()

print(f"element at 2nd index = {my_list.get(2)}")
my_list.erase(1)
my_list.display()