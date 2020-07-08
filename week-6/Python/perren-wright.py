
final = {}
class Node:
    def __init__(self, data = None):
        self.left = None
        self.right = None
        self.data = data
    
    def insert(self, val):
        if(val <= self.data):
            if(self.left == None):
                self.left = Node(val)
            else:
                self.left.insert(val)
        else:
            if(self.right == None):
                self.right = Node(val)
            else:
                self.right.insert(val)
    
    def printtree(self):
        if(self.left == None and self.right == None):
            print(self.data)
        else:
            self.left.printtree()
            print(self.data)
            self.right.printtree()
    
    def iterate(self, dict, parent):
        if(self.left == None and self.right == None):
            dict[self.data] = parent.data
        else:
            self.left.iterate(dict, parent)
            self.right.iterate(dict, parent)
            dict[self.data] = parent.data        
        return dict

def findmaxdiff(tree):
    if(tree.right != None or tree.left != None):
        final.update(tree.iterate({}, tree))
        final.update(findmaxdiff(tree.left))
        final.update(findmaxdiff(tree.right))
    return final
    
            

def main():
    tree = Node(4)
    tree.insert(2)
    tree.insert(1)
    tree.insert(3)
    tree.insert(6)
    tree.insert(5)
    tree.insert(7)
    print(findmaxdiff(tree))
    

if __name__ == "__main__":
    main()

        
