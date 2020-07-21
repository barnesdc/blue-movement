from binarytree import build

def leaf_to_root(root, arr):

    if root == None:
        return None

    arr.append(root.val)

    if (root.left == None) and (root.right == None):
        print(arr)
    
    leaf_to_root(root.left, arr)
    leaf_to_root(root.right, arr)


def mirror(root):

    if root:
        # Swaps left and right nodes.
        temp = root.left
        root.left = root.right
        root.right = temp
        # Swaps left and right nodes of children recursively.
        mirror(root.left)
        mirror(root.right)
    
    return root

def diff_helper(root):
    d = 0
    if root:
        l = diff_helper(root.left)
        r = diff_helper(root.right)

        d = abs(root.val - min(l, r))
    return d

        
# Function currently only works for sample case.
def max_diff(root):
    if root == None:
        return 0

    arr = []
    
    arr.append(diff_helper(root.left))
    arr.append(diff_helper(root.right))
    
    return max(arr)    

nodes = [1, 2, 3, 4, 5, 6, 7, None, None, None, None, 8, 9]
tree = build(nodes)

print(tree)
arr = []
leaf_to_root(tree, arr)

nodes_2 = [1, 2, 3, 4, 5, 6, 7]
second = build(nodes_2)

print(second)
print(mirror(second))

nodes_3 = [6, 3, 8, None, None, 2, 4, None, None, None, None, 1, 7]
third = build(nodes_3)
print(third)
print(max_diff(third))
