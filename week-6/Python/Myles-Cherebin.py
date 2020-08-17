class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

    def print(self):
        a = self.head
        out = ""
        while (a is not None):
            out = out + str(a.data) + "->"
            a = a.next

        out += "NULL"

        print(out)

def print_all_paths(node, path):
    if (node is None):
        return
    path.append(node.val)
    if (node.left is None and node.right is None):
        path.reverse()
        print(path)
        path.reverse()
    else:
        print_all_paths(node.left, path)
        print_all_paths(node.right, path)
    path.pop()

def print_all(node):
    path = []
    print_all_paths(node,path)



def max_dif_help(Node, maxdif):
  if (Node.left is None and Node.right is None):
    return (maxdif - Node.val)

  maxdif = max(maxdif, Node.val)

  if (Node.left is not None):
    dif_left = max_dif_help(Node.left,maxdif)
  else:
    dif_left = 0

  if (Node.right is not None):
    dif_right = max_dif_help(Node.right,maxdif)

  else:
    dif_right = 0
  return max(maxdif - Node.val, max(dif_left,dif_right))

def max_dif(Node):
  if (Node.left is None and Node.right is None):
    return Node.val

  maxdif = max_dif_help(Node, Node.val)
  return(maxdif)


# PROMPT 3 CONVERT A TREE TO ITS MIRROR
def mirror_swap(node):
    if((node.left is not None) or (node.right is not None)):
         temp = node.left
         node.left = node.right
         node.right = temp
         mirror_swap(node.left)
         mirror_swap(node.right)


if __name__ == "__main__":
    print("This is the tree")
    print()
    print("   10   ")
    print("  /  \  ")
    print(" 6    7 ")
    print("/ \  / \\")
    print("2 3  4   5")

    a = Node(10)
    b = Node(6)
    c = Node(7)
    b.left = Node(2)
    b.right = Node(3)
    c.left = Node(4)
    c.right = Node(5)

    a.left = b
    a.right = c
    print()
    print("from left to right, the paths are:")
    print_all(a)

    print()
    print()

    mirror_swap(a)
    print("after being mirrored, from left to right, the paths are:")
    print_all(a)

    print()
    print()
    
    print("maximum difference of tree is " + str(max_dif(a)))
    print("maximum difference of left subtree is " + str(max_dif(b)))
    print("maximum difference of right subtree is " + str(max_dif(c)))
