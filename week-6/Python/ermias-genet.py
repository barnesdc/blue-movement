#First problem
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
def max_diff(self, root):
    if not root:  
        return 0
    return self.helper(root, root.val, root.val)
    
def helper(self, node, mx, mn):
    if not node:
        return mx - mn
    mx = max(mx, node.val)
    mn = min(mn, node.val)
    return max(self.helper(node.left, mx, mn), self.helper(node.right, mx, mn))

#Second problem
  
def print_path(root): 
    path = [] 
    print_path_helper(root, path, 0) 

def print_path_helper(root, path, path_len): 
    if root is None: 
        return 
    if(len(path) > path_len):  
        path[path_len] = root.data 
    else: 
        path.append(root.data) 
    path_len = path_len + 1
    if root.left is None and root.right is None: 
        print_array(path, path_len) 
    else: 
        print_path_helper(root.left, path, path_len) 
        print_path_helper(root.right, path, path_len) 
def print_array(int, len): 
    for i in int[0 : len]: 
        print(i," ",end="") 
    print()

#Third problem

def pre_order(root):
    if root is None:
        return
    print(root.data, end=' ')
    pre_order(root.left)
    pre_order(root.right)

def flip(root):
    if root is None:
        return
    temp = root.left
    root.left = root.right
    root.right = temp

def mirror(root):
    if root is None:
        return
    mirror(root.left)
    mirror(root.right)
    flip(root)