from collections import deque


# Node Class
class Node:
  def __init__(self, data, left=None, right=None):
    self.left = left
    self.right = right
    self.data = data

# Binary Tree Class
class BinaryTree:
  def __init__(self):
    self.root = None
    self.size = 0
    self.height = self.maxLeafDepth = 0
    self.minLeafDepth = 0
    self.leafCount = 0


  # Builds a Binary Tree from a list and returns the root
  # Assume the list is in Breadth-first search / level order
  # https://en.wikipedia.org/wiki/Tree_traversal#Breadth-first_search_/_level_order
  def buildFromList(self, l: list) -> Node:
    bfs_data = deque([None if data is None else Node(data) for data in l])  # Turn list into queue of Nodes
    self.root = bfs_data.popleft() if len(bfs_data) != 0 else None          # First Node becomes the root
    parent_queue = deque([self.root])

    while len(bfs_data) > 0:  # While we have data to insert
      leftChild = bfs_data.popleft() if len(bfs_data) != 0 else None    # First data becomes left child
      rightChild = bfs_data.popleft() if len(bfs_data) != 0 else None   # Second becomes right child
      parent = parent_queue.popleft()                                   # Parent of the children
      if leftChild != None:                                             # Assign children to the parent 
        parent.left = leftChild                                         # and add the children to the parent queue
        parent_queue.append(leftChild)
      if rightChild != None:
        parent.right = rightChild
        parent_queue.append(rightChild)

    self.__generateProperties()   # Generate helpful properties now that a Binary Tree has been constructed
    return self.root


  # Converts the Binary Tree to a list by Breadth-first search / level order and returns it
  def buildToList(self):
    curLevel = [self.root]  # Start with root level (level 0)
    hasMoreNodes = True
    l = []

    while hasMoreNodes:
      hasMoreNodes = False
      nextLevel = []        # Children of the current level nodes well be parents in the next level

      for node in curLevel:
        if node is None:
          l.append(None)    # Means this child doesn't exist 
          continue
        if node.left is not None or node.right is not None:
          hasMoreNodes = True   # Continue because we have more children
        l.append(node.data)     # Append this node's data to list
        nextLevel.extend((node.left, node.right)) # Append this node's children for next level processing

      curLevel = nextLevel

    while l and l[-1] is None:  # Remove any trailing None's as they aren't necessary
      l.pop()
    
    return l


  # Computes size, height, max and min depth, and leaf count for the Binary Tree 
  def __generateProperties(self):
    size = 0
    leaf_count = 0
    minLeafDepth = 0
    maxLeafDepth = -1
    curLevel = [self.root]

    while len(curLevel) > 0:
      maxLeafDepth += 1
      nextLevel = []

      for node in curLevel:
        size += 1

        # Leaf Node
        if node.left is None and node.right is None:
          if minLeafDepth == 0:
            minLeafDepth = maxLeafDepth
          leaf_count += 1

        if node.left is not None:
          nextLevel.append(node.left)

        if node.right is not None:
          nextLevel.append(node.right)
      
      curLevel = nextLevel

    self.size = size
    self.height = self.maxLeafDepth = maxLeafDepth
    self.minLeafDepth = minLeafDepth
    self.leafCount = leaf_count
  


# Find Maximum Difference Between a Node and its Descendants in a Binary Tree.
# https://ibb.co/563hJSG
def maxDiff(root: Node) -> int:
  if root.left is None and root.right is None: return root.data

  def recurse(root, maxVal):
    if root.left is None and root.right is None: return maxVal - root.data
    maxVal = max(maxVal, root.data)
    diffLeft = recurse(root.left, maxVal) if root.left is not None else 0
    diffRight = recurse(root.right, maxVal) if root.right is not None else 0
    return max(maxVal - root.data, max(diffLeft, diffRight))

  return recurse(root, root.data)

  

# Write an algorithm to print leaf to root path for every leaf node of the binary tree.
# https://ibb.co/G7sZnDZ
def printLeafToRootPaths(root: Node):
  queue = deque()

  def recurse(root, q):
    if root is None: return
    q.append(root.data)

    if root.left is None and root.right is None:
      for i in range(len(queue) - 1):
        print(q[-i-1], end='->')
      print(q[0])

    recurse(root.left, q)
    recurse(root.right, q)
    q.pop() # ! Need to remove current node once both left and right subtrees are explored

  recurse(root, queue)



# Write an algorith to convert a tree to its mirror.
# https://ibb.co/H40dhCt
# Same code as the buildToList() method in BianryTree class except one line changed
# nextLevel.extend((node.left, node.right)) -> nextLevel.extend((node.right, node.left))
def mirror(root: Node) -> BinaryTree:
  curLevel = [root]
  hasMoreNodes = True
  l = []

  while hasMoreNodes:
    hasMoreNodes = False
    nextLevel = []
    for node in curLevel:
      if node is None:
        l.append(None)
        continue
      if node.left is not None or node.right is not None:
        hasMoreNodes = True
      l.append(node.data)
      nextLevel.extend((node.right, node.left))   # Flip the right and left children
    curLevel = nextLevel
  while l and l[-1] is None:
    l.pop()

  mirror_tree = BinaryTree()
  mirror_tree.buildFromList(l)
  return mirror_tree




# ~~~~~~~~~~~~~~~~~~~ Prompt 1 Tests ~~~~~~~~~~~~~~~~~~~ #
prompt_1 = BinaryTree()

# Test 1: https://ibb.co/563hJSG
root = prompt_1.buildFromList([6,3,8,None,None,2,4,1,7,None,None])
print(maxDiff(root)) # 7

# Test 2
'''                      
       5
      /  \
     4    8
    /    / \
   11   17  4
  /        /
 7        5
'''
root = prompt_1.buildFromList([5,4,8,11,None,17,4,7,None,None,None,5])
print(maxDiff(root)) # 4
print()



# ~~~~~~~~~~~~~~~~~~~ Prompt 2 Tests ~~~~~~~~~~~~~~~~~~~ #
prompt_2 = BinaryTree()

# Test 1: https://ibb.co/G7sZnDZ
root = prompt_2.buildFromList([1,2,3,4,5,6,7,None,None,None,None,8,9,None,None])
printLeafToRootPaths(root); print()

# Test 2: https://ibb.co/563hJSG
root = prompt_2.buildFromList([6,3,8,None,None,2,4,1,7,None,None])
printLeafToRootPaths(root); print()

# Test 3:
'''                      
       5
      /  \
     4    8
    /    / \
   11   17  4
  /        /
 7        5
'''
root = prompt_2.buildFromList([5,4,8,11,None,17,4,7,None,None,None,5])
printLeafToRootPaths(root); print()



# ~~~~~~~~~~~~~~~~~~~ Prompt 3 Tests ~~~~~~~~~~~~~~~~~~~ #
prompt_3 = BinaryTree()

# Test 1: https://ibb.co/H40dhCt
root = prompt_3.buildFromList([1,2,3,4,5,6,7])
mirror_tree = mirror(root)
print(mirror_tree.buildToList())  # [1,3,2,7,6,5,4]

# Test 2: https://ibb.co/563hJSG
root = prompt_3.buildFromList([6,3,8,None,None,2,4,1,7,None,None])
mirror_tree = mirror(root)
print(mirror_tree.buildToList())  # [6,8,3,4,2,None,None,None,None,7,1]

# Test 3: https://ibb.co/G7sZnDZ
root = prompt_3.buildFromList([1,2,3,4,5,6,7,None,None,None,None,8,9,None,None])
mirror_tree = mirror(root)
print(mirror_tree.buildToList())  # [1,3,2,7,6,5,4,None,None,9,8]

# Test 4
'''                      
       5
      /  \
     4    8
    /    / \
   11   17  4
  /        /
 7        5
'''
root = prompt_3.buildFromList([5,4,8,11,None,17,4,7,None,None,None,5])
mirror_tree = mirror(root)
print(mirror_tree.buildToList())  # [5,8,4,4,17,None,11,None,5,None,None,None,7]
