#!/usr/bin/env python3
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


def mirror(node):

    if node == None:
        return
    else:

        temp = node

        mirror(node.left)
        mirror(node.right)

        temp = node.left
        node.left = node.right
        node.right = temp


def printPaths(root):
    path = []
    printPathsRec(root, path, 0)

def printPathsRec(root, path, pathLen):
    if root == None:
        return

    if (len(path) > pathLen):
        path[pathLen] = root.val

    else:
        path.append(root.val)

    pathLen += 1

    if (root.left == None) and (root.right == None):
        printArray(path, pathLen)
    else:
        printPathsRec(root.left, path, pathLen)
        printPathsRec(root.right, path, pathLen)

def printArray(nodes, length):
    for i in nodes[0:length]:
        if nodes[-1]==i:
            print(i, end="")
        else:
            print(i, end="-> ")

def getbranch(root):
    branch = []
    result = []

    if root == None:
        return
    branch.append(root.val)

    getbranch(root.left)
    getbranch(root.right)
    result.append(branch)
    return result
def maxdif(node):

    max = 0
    temp = node

    branches = getbranch(node)

    for each_branch in branches:
        for i in range(len(each_branch)-1):
            dif = each_branch[i] - each_branch[i+1]

            if dif > max:
                max = dif

    return max

def printTree(node):

    if node == None:
        return

    printTree(node.left)
    print(node.val)
    printTree(node.right)

def main():
    root = Node(6)
    root.left = Node(7)
    root.right = Node(10)
    root.left.left = Node(5)
    root.left.right = Node(2)
    root.right.right = Node(3)
    root.right.left = Node(1)

    printTree(root)

    dif = maxdif(root)
    print(dif)

    print()
    printPaths(root)

    print()
    mirror(root)
    printTree(root)
