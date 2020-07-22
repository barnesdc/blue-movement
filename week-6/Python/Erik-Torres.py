# Find Maximum Difference Between a Node and its Descendants in a Binary Tree..

class tree_node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def max_difference(root, diff=float('-inf')):
    if root is None:
        return float('inf'), diff

    leftVal, diff = max_difference(root.left, diff)
    rightVal, diff = max_difference(root.right, diff)
    currentDiff = root.key - min(leftVal, rightVal)

    diff = max(diff, currentDiff)

    return min(min(leftVal, rightVal), root.key), diff


root = tree_node(6)
root.left = tree_node(3)
root.right = tree_node(8)
root.right.left = tree_node(2)
root.right.right = tree_node(4)
root.right.left.left = tree_node(1)
root.right.left.right = tree_node(7)

print(max_difference(root)[1],'\n')


# Write an algorithm to print leaf to root path for every leaf node of the binary tree.

class node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def print_paths(root):
    # list to store path
    path = []
    print_paths_rec(root, path, 0)


def print_paths_rec(root, path, pathLen):

    if root is None:
        return

    if (len(path) > pathLen):
        path[pathLen] = root.data
    else:
        path.append(root.data)

    pathLen = pathLen + 1

    if root.left is None and root.right is None:

        print_array(path, pathLen)
    else:

        print_paths_rec(root.left, path, pathLen)
        print_paths_rec(root.right, path, pathLen)


def print_array(ints, len):
    for i in range(len-1,0,-1):
        print(ints[i], "->", end="")
    print(ints[0])
    print()


root = node(10)
root.left = node(8)
root.right = node(2)
root.left.left = node(3)
root.left.right = node(5)
root.right.left = node(2)
print_paths(root)


# Write an algorithm to convert a tree to its mirror.

class new_node:
    def __init__(self, data):
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



def in_order(node):
    if (node == None):
        return

    in_order(node.left)
    print(node.data, end=" ")
    in_order(node.right)


if __name__ == "__main__":
    root = new_node(1)
    root.left = new_node(2)
    root.right = new_node(3)
    root.left.left = new_node(4)
    root.left.right = new_node(5)

    print("tree is: ")
    in_order(root)

    mirror(root)

    print("\nmirror tree is: ")
    in_order(root)
