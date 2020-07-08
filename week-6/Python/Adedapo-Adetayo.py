#prompt 1
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def maxDifference(root, diff=float('-inf')):

    if root is None:
        return float('inf'), diff

    left, diff = maxDifference(root.left, diff)
    right, diff = maxDifference(root.right, diff)

    d = root.data - min(left, right)

    diff = max(diff, d)
    return min(min(left, right), root.data), diff

#Prompt 2
from collections import deque

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def leaftoRoot(root):

    stack = deque()
    stack.append((root, ""))

    while stack:

        curr, path = stack.pop()

        path = str(curr.data) + (" -> " if path else "\n") + path
        if curr.left is None and curr.right is None: 
            print(path, end='')
        if curr.right:
            stack.append((curr.right, path))

        if curr.left:
            stack.append((curr.left, path))

#Prompt 3
class newNode: 
 	def __init__(self,data): 
 		self.data = data 
 		self.left = self.right = None


def mirror(node):  
  
    if (node == None): 
        return
    else: 
  
        temp = node    
        
        mirror(node.left)  
        mirror(node.right)  
  
        temp = node.left  
        node.left = node.right  
        node.right = temp  
  
def inOrder(node) : 
  
    if (node == None):  
        return
          
    inOrder(node.left)  
    print(node.data, end = " ")  
    inOrder(node.right) 