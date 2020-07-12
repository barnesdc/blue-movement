from collections import deque


# Data structure to store a Binary Tree BinaryTree

class BinaryTree:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


#function to find maximum difference between a BinaryTree and its
# descendants in a binary tree
def maximum_Difference(root, diff=float('-inf')):

    if root is None:
        return float('inf'), diff

    # recursion
    left, diff = maximum_Difference(root.left, diff)
    right, diff = maximum_Difference(root.right, diff)

   
    d = root.data - min(left, right)

   
    diff = max(diff, d)

    
    return min(min(left, right), root.data), diff

#function to print all leaf to root path for every leaf BinaryTree
#in a binary tree. 

#check if BinaryTree or not

def check_leaf_BinaryTree(BinaryTree):
    return BinaryTree.left is None and BinaryTree

#print leaf to root path for a given leaf

def leaf_root_path(leaf_BinaryTree, dict):
    currnt = leaf_BinaryTree
    while dict[currnt]:
        print(currnt.data, end=" >")
        currnt = dict[currnt]
    print(currnt.data)


#print root to leaf 
def Path_root_leaf(curr, dict):

    
    if curr is None:
        return

   
    Path_root_leaf(dict[curr], dict)
    print(curr.data, end=" -> ")


def print_path(leafBinaryTree, dict):

    
    curr = leafBinaryTree

    
    while dict[curr]:
        print(curr.data, end=" -> ")
        curr = dict[curr]

    print(curr.data)


# print leaf to root path for every leaf BinaryTree

def postorder_loop(root):

    # empty stack
    stack = deque()

    # empty dictionary(hashmap)
    dict = {}


    dict[root] = None

    # push root BinaryTree
    stack.append(root)

    #while stack not empty(loop)
    while stack:

        curr = stack.pop()

        
        if check_leaf_BinaryTree(curr):
           
           print_path(curr, dict)

        

       
        if curr.right:
            stack.append(curr.right)
            dict[curr.right] = curr

        if curr.left:
            stack.append(curr.left)
            dict[curr.left] = curr

# Creating binary tree 
# from given list 
#mirror function starts below
from binarytree import tree, Node, build

# List of nodes 
# nodes =[1,2,3,4,5,6,7] 

# # Builidng the binary tree 
# binary_tree = build(nodes) 
# print('Binary tree from list :\n', 
# 	binary_tree) 

# # Getting list of nodes from 
# # binarytree 
# print('\nList from binary tree :', 
# 	binary_tree.values) 

# #swap function
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

print(root)

def mirror(root): 
  
    if (root == None): 
        return
  
    q = [] 
    q.append(root) 
  
    
    while (len(q)): 
  
        
        curr = q[0] 
        q.pop(0) 
  
        # swap left child with right child 
        curr.left, curr.right = curr.right, curr.left 
  
        # append left and right children 
        if (curr.left): 
            q.append(curr.left) 
        if (curr.right): 
            q.append(curr.right) 
mirror(root)
root.preorder
print("")

print('After mirroring', root)

if __name__ == '__main__':

    """ tree diagram below
              6
            /   \
           /     \
          3       8
                /   \
               /     \
              2       4
            /   \
           /     \
          1       7
    """

    root = BinaryTree(6)
    root.left = BinaryTree(3)
    root.right = BinaryTree(8)
    root.right.left = BinaryTree(2)
    root.right.right = BinaryTree(4)
    root.right.left.left = BinaryTree(1)
    root.right.left.right = BinaryTree(7)

    print("Maximum difference = ",maximum_Difference(root)[1])

    print("")

    


    """ tree diagram below
               1
             /   \
            /      \
           /       \
          2           3
         / \       / \
        /   \     /    \
       4     5   6      7
                / \
               /   \
              8        9
    """

    root = BinaryTree(1)
    root.left = BinaryTree(2)
    root.right = BinaryTree(3)
    root.left.left = BinaryTree(4)
    root.left.right = BinaryTree(5)
    root.right.left = BinaryTree(6)
    root.right.right = BinaryTree(7)
    root.right.left.left = BinaryTree(8)
    root.right.left.right = BinaryTree(9)

    postorder_loop(root)
