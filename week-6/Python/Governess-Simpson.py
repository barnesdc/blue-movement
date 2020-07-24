from typing import List

# Node class for the three prompts.
class Node:
    def __init__(self, data, left=None, right=None):
        self.left = left
        self.right = right
        self.data = data

    # Prompt 1: Find Maximum Difference Between a Node and its Descendants 
    # in a Binary Tree. https://ibb.co/563hJSG

    def maxDifference(self, root):
        if root is None:
            return root
        self.diff = 0

        # Inner function that performs depth-first traversal to find the greatest difference between
        # the node and its children.
        # This is my recursive solution!
        def DFS(root, maxi, mini):
            if root:
                self.diff = max(self.diff, abs(root.data - maxi), abs(root.data - mini))
                maxi = max(root.data, maxi)
                mini = min(root.data, mini)
                DFS(root.left, maxi, mini)
                DFS(root.right, maxi, mini)

        DFS(root, root.data, root.data)
        return self.diff


# Prompt 2: Write an algorithm to print leaf to root path for every 
# leaf node of the binary tree. https://ibb.co/G7sZnDZ


    def leafToRootPath(self, root) -> List[str]:
        if not root:
            return [] 
        
        # Stores the pair value of the root itself and the data it contains
        # This will allow us to both keep track of the path, as well as traverse
        # through the tree
        root_leaf_stack = [(root, str(root.data))]
        output = []

        # Continuously traverses tree and adds node value to the path until it
        # can't go any further. That "path" is then stored.
        while root_leaf_stack:
            node, path = root_leaf_stack.pop()
            if node.left:
                root_leaf_stack.append((node.left, path + "->" + str(node.left.data)))

            if node.right:
                root_leaf_stack.append((node.right, path + "->" + str(node.right.data)))

            if not node.left and not node.right:
                output.append(path)
        return output

# Prompt 3: Write an algorith to convert a tree to its mirror. 
# https://ibb.co/H40dhCt

    def treeMirror(self, root):
        if not root:
            return -1
        
        # Stack data structure is perfect for getting the most recent values of the tree
        mirror_stack = [root]
        print(root.data)
        while mirror_stack:
            node = mirror_stack.pop()
            if node is None:
                continue

            # Reverses the left and right sides of the node in question
            node.left, node.right = node.right, node.left

            # Not fully sure how to print the trees in a cleaner fashion, but this
            # works for now. Prints the value of the node starting from the root,
            # always goes right to left, then moves down node (to the right).
            mirror_stack.append(node.left)
            if node.left != None:
                print(node.left.data)

            mirror_stack.append(node.right)
            if node.right != None:
                print(node.right.data)
        return root

p1_root = Node(6)
p1_root.left = Node(3)
p1_root.right = Node(8)
p1_root.right.left = Node(2)
p1_root.right.right = Node(4)
p1_root.right.left.left = Node(1)
p1_root.right.left.right = Node(7)

p2_root = Node(1)
p2_root.left = Node(2)
p2_root.right = Node(3)
p2_root.right.left = Node(4)
p2_root.right.right = Node(5)
p2_root.right.left.left = Node(6)
p2_root.right.left.right = Node(7)

print(p1_root.maxDifference(p1_root))
print(p1_root.leafToRootPath(p1_root))
print(p1_root.treeMirror(p1_root))

print(p2_root.maxDifference(p2_root))
print(p2_root.leafToRootPath(p2_root))
print(p2_root.treeMirror(p2_root))

