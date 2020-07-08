# -*- coding: utf-8 -*-
"""
Created on Tue Jul  7 21:23:04 2020

@author: andre
"""

class Node():
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
            
def print_tree(temp_node):
    if (not temp_node):
        return    
    print_tree(temp_node.left)
    print(temp_node.data, end = " ")
    print_tree(temp_node.right)
def size(node):
    if node is None:
        return 0
    else:
        return(size(node.left) + 1 + size(node.right))
    
def insert(temp_node, insertion):
    nodes = []
    nodes.append(temp_node)
    
    while(len(nodes)):
        temp_node = nodes[0]
        nodes.pop(0)
        
        if (not temp_node.left):
            temp_node.left = Node(insertion)
            break
        else:
            nodes.append(temp_node.left)
        if (not temp_node.right):
            temp_node.right = Node(insertion)
            break
        else:
            nodes.append(temp_node.right)
            

def min_max(minim, node, maxim):
    if node == None:
        return [maxim, minim]
    if node.left == None and node.right == None:
            return [node.data, minim]
    min_max1 = min_max(minim, node.left, maxim)
    minim = min_max1[1]
    min_max2 = min_max(minim, node.right, maxim)
    minim = min_max2[1]
    minim2 = min(min_max1[0], min_max2[0])
    minim = max(minim, node.data - minim2)
    return [min(minim2, node.data), minim]


def max_tree_diff(node):
    if size(node) < 2:
        raise Exception("tree must have at least two nodes")
    else:
        minim = node.data
        maxim = node.data
        return min_max(minim, node, maxim)[1]
    
def leaf_to_root(root):
    final_paths1 = []
    final_paths2 = []
    if root == None:
        return []
    else:
        paths1 = leaf_to_root(root.left)
        paths2 = leaf_to_root(root.right)
        if paths1 == [] and paths2 == []:
            final_paths = [root.data]
        else:
            if len(paths1) == 1:
                final_paths1.append(paths1 + [root.data])
            else:     
                for path in paths1:
                    final_paths1.append(path + [root.data])
            if len(paths2) == 1:
                final_paths2.append(paths2 + [root.data])
            else:
                for path in paths2:
                    final_paths2.append(path + [root.data])
            final_paths = final_paths1 + final_paths2
        return final_paths
    
def mirror_tree(root):
    if root == None:
        return None
    else:
        left = mirror_tree(root.right)
        right = mirror_tree(root.left)
        root.left = left
        root.right = right
    return root
        
        

two = Node(2)
two.left = Node(1)
two.right= Node(7)
eight = Node(8)
eight.left = two
eight.right = Node(4)
six = Node(6)
six.right = eight
six.left = Node(3)

mirror_two = Node(2)
mirror_two.left = Node(4)
mirror_two.right = Node(5)
mirror_three = Node(3)
mirror_three.left = Node(6)
mirror_three.right = Node(7)
mirror_one = Node(1)
mirror_one.left = mirror_two
mirror_one.right = mirror_three

print(max_tree_diff(six))
print(leaf_to_root(six))
answer = mirror_tree(mirror_one)
print_tree(mirror_one.left)
print_tree(mirror_one.right)