# Austen Williams 
# Week 6 Prompts 1 , 2 , & 3

"""
1) Find Maximum Difference Between a Node and its Descendants in a Binary Tree. 
    
   Example: https://ibb.co/563hJSG

2) Write an algorithm to print leaf to root path for every leaf node of the binary tree. 

   Example: https://ibb.co/G7sZnDZ

3) Write an algorith to convert a tree to its mirror. 

   Example: https://ibb.co/H40dhCt

"""


class Node:
    'Node class that holds pointers to left and right nodes'
    
    def __init__(self, data, left=None, right=None):
        self.left = left
        self.right = right
        self.data = data
        

class BinaryTree:
    'BinaryTree class representing BinaryTree'
    
    def __init__(self, root = None):
        self.root = root
        self.tree = list()
    
    def printTree(self):
        'Prints BinaryTree representation of root node in center'
        if self.root != None:
            self._printTree(self.root)
        else:
            print("None")
    
    def _printTree(self, node):
        'helper function used to print tree recursively'
        if node != None:
            self._printTree(node.left)
            print(node.data, end = " ")
            self._printTree(node.right)
    
    def treeToList(self):
        'function used to convert tree into a list'
        if self.root != None:
            self._treeToList(self.root)
            return self.tree
        else:
            return self.tree
        
    def _treeToList(self, node):
        'recursive function that converts tree into list'
        if node != None:
            self._treeToList(node.left)
            self.tree.append(node.data)
            self._treeToList(node.right)


                             
class Week6:
    'Class that performs all prompt operations on BinaryTrees'
    
    def __init__(self):
        'initializes answer to be returned for maxDiff function'
        self.ans = 0
    
    def maxDiff(self, node):
        'Function that calculates the maximum difference of a child and its decendents'
        if node == None:
            return 0
        self._maxDiff(node, node.data, node.data)
        return self.ans
    
    def _maxDiff(self, node, minVal, maxVal):
        'helper function that recursively finds the max difference between a child and descendent node'
        if node == None:
            return
        self.ans = max(self.ans, max(abs(node.data - minVal), abs(maxVal - node.data)))
        maxVal = max(maxVal, node.data)
        minVal = min(minVal, node.data)
        self._maxDiff(node.left, minVal, maxVal)
        self._maxDiff(node.right, minVal, maxVal)
        
    
    def printNodePaths(self, node):
        'function that prints all leaf to root path for every leaf in the binary tree'
        if node == None:
            print("None")
        else:
            lst = list()
            self._printNodePaths(node, lst)
            
    
    def _printNodePaths(self, node, lst):
        'helper function that recursively prints the leaf to root path'
        if node == None:
            return 
        lst.append(node.data)
        if node.left == None and node.right == None:
            lst.reverse()
            print(lst)
            lst.reverse()
        self._printNodePaths(node.left, lst)
        self._printNodePaths(node.right, lst)
        lst.pop()
                
            
    
    def mirror(self,node):
        'recursive function used to mirror a binary tree'
        if node == None:
            return
        self.mirror(node.left)
        self.mirror(node.right)
        temp = node.left
        node.left = node.right
        node.right = temp





if __name__ == "__main__":
    
    
    
    def testMaxDiff():
        """
        Tree:
                6
               / \
              3   8
                 / \
                2  4
               / \ 
              1  7   
        """
        root = Node(6)
        root.left = Node(3)
        root.right = Node(8)
        root.right.left = Node(2)
        root.right.right = Node(4)
        root.right.left.left = Node(1)
        root.right.left.right = Node(7)
        tree = BinaryTree(root)
        test = Week6()
        testArr = [6,3,8,2,4,1,7]
        ans = max(testArr) - min(testArr)
        maxDiff = test.maxDiff(tree.root)
        print()
        if maxDiff != ans:
            print(f'Wrong results for maxdDiff expected {ans} recieved {test.maxDiff(tree.root)}.')
        else:
            print("Maxdiff testcases passed")
            
        
    
    
    def testRootPaths():
        """
        Tree:
                1
               / \
              2   3
             /\  / \
            4 5 6  7
               / \ 
              8  9   
        """
        root = Node(1)
        root.left = Node(2)
        root.left.left = Node(4)
        root.left.right = Node(5)
        root.right = Node(3)
        root.right.left = Node(6)
        root.right.right = Node(7)
        root.right.left.left = Node(8)
        root.right.left.right = Node(9)
        tree = BinaryTree(root)
        test = Week6()
        ans = [[4, 2, 1],[5, 2, 1],[8, 6, 3, 1],[9, 6, 3, 1],[7, 3, 1]]
        print()
        print('**** The correct answer ********')
        print()
        for i in ans:
            print(i)
        print()
        print('******** answer given by function ********')
        print()
        test.printNodePaths(tree.root)
        
        
        
        
        
    
    def testMirror():
        """
        Tree:
                1
               / \
              2   3
             /\  / \
            4 5 6  7
    
        """
        root = Node(1)
        root.left = Node(2)
        root.left.left = Node(4)
        root.left.right = Node(5)
        root.right = Node(3)
        root.right.left = Node(6)
        root.right.right = Node(7)
        tree = BinaryTree(root)
        test = Week6()
        testArr = [4,2,5,1,6,3,7]
        ans = testArr.reverse()
        mirror = test.mirror(tree.root)
        print()
        if mirror != ans:
            print(f'Wrong resuslts for mirror expected {ans} received {mirror}')
        else:
            print("Mirror test cases passed")
    
    testMaxDiff()
    testRootPaths()
    testMirror()
        
    """
    Maxdiff testcases passed

    **** The correct answer ********

    [4, 2, 1]
    [5, 2, 1]
    [8, 6, 3, 1]
    [9, 6, 3, 1]
    [7, 3, 1]

    ******** answer given by function ********

    [4, 2, 1]
    [5, 2, 1]
    [8, 6, 3, 1]
    [9, 6, 3, 1]
    [7, 3, 1]

    Mirror test cases passed

    """
        
        
    
    
    
    
        
        
        
        
                
                
                
    
