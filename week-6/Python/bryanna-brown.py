from binarytree import build,Node

# Find Maximum Difference Between a Node and its Descendants in a Binary Tree
"""
This one does not work because I ran out of time while debugging:

Idea:
perform a DFS algorithm on the tree to find each difference and update the 
max difference while travesing through the tree
"""

def dfsDiff(minSide,maxSide,maxDiff,treeRoot):
    if treeRoot == None:
        return
    
    rootMin = abs(treeRoot.val - minSide)
    rootMax = abs(treeRoot.val - maxSide)

    maxDiff = max(maxDiff,rootMin,rootMax,)

    dfsDiff(min(treeRoot.left.val,treeRoot.right.val),max(treeRoot.left.val,treeRoot.right.val),maxDiff, treeRoot.left)
    dfsDiff(min(treeRoot.left.val,treeRoot.right.val),max(treeRoot.left.val,treeRoot.right.val),maxDiff, treeRoot.right)

nodes = [3,6,8,2,11,112,13, 50, 20, None, 9, 0 ,7]
binary_tree = build(nodes)
print(binary_tree)

#maxVal = 0
#dfsDiff(binary_tree,binary_tree,maxVal,binary_tree)
#print(maxVal)

# Write an algorithm to print leaf to root path for every leaf node of the binary tree.

"""
Idea:
perform a DFS algorithm on the tree and return all of the paths found
"""
def dfsPaths(currPath,treeRoot):
    path = []
    path = path + currPath
    if treeRoot == None:
        return
    path.append(treeRoot.val)

    if(treeRoot.left == None) and (treeRoot.right == None):
        print(path)
        return
    else:
        dfsPaths(path, treeRoot.left)
        dfsPaths(path, treeRoot.right)

nodes = [3,6,8,2,11,112,13, 50, 20, None, 9, 0 ,7]
binary_tree = build(nodes)
print(binary_tree)
path = []
dfsPaths(path,binary_tree)


# Write an algorith to convert a tree to its mirror.