class Node:
    
    # this initialize data member 
    def __init__(self,data):
        self.left = None
        self.right = None
        self.data = data

    '''
        this function call recursive from root to leaf node
    '''
    def print_leaf_to_root(self,n):

        # creating list leaf to root node
        L = TreeList(self.data,n)
        if self.left is not None:
            l = self.left
            l.print_leaf_to_root(L)
        if self.right is not None:
            r = self.right
            r.print_leaf_to_root(L)

        if self.left is None and self.right is None:
            L.print_list()

'''
    this class for list of data node leaf node to root node
'''
class TreeList:
    def __init__(self,data,nex):
        self.next=nex
        self.data=data

    '''
        this function print list 
    '''
    def print_list(self):
        if self.next is None:
            print(self.data)
        else:
            print(self.data,end=' ->')
            self.next.print_list()


'''
    this code for test recursion function
    as given tree in question
'''
root = Node(1)
l= root.left= Node(2)

l.left=Node(4)
l.right= Node(5)
r= root.right = Node(3)
l = r.left = Node(6)
l.left= Node(8)
l.right = Node(9)
root.right.right = Node(7)

# call the function to print
root.print_leaf_to_root(None);
