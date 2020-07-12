class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

    def print_all_paths(node, path):
        if (node is None):
            return

        path.append(node.val)

        if (node.left is None and node.right is None):
            path.reverse()
            print(path)
            path.reverse()
        else:
            node.left.print_all_paths(path)
            node.right.print_all_paths( path)

        path.pop()

    def print_all(node):
        path = []

        node.print_all_paths(path)



    def max_dif_help(Node,val, max):
        if (Node.left is None and Node.right is None):
            return

        if (Node.left is not None):
            if (val - Node.left.val > max):
                max = val - Node.left.val

        if (Node.right is not None):
            if (val - Node.right.val > max):
                max = val - Node.right.val

        max_dif_help(Node.left, val, max)

    def max_dif(Node):
        max = 0
        val = Node.val
        temp = Node.left

        while (temp is not None):
            if (val - temp.val > max):
                max = val - temp.val

                temp = temp.left
            else:
                temp = temp.left

        return(max)


# PROMPT 3 CONVERT A TREE TO ITS MIRROR
    def mirror_swap(node):
        if((node.left is not None) or (node.right is not None)):
             temp = node.left
             node.left = node.right
             node.right = temp

             node.left.mirror_swap()
             node.right.mirror_swap()        


if __name__ == "__main__":
 '''      10
         /  \
        6    7
       / \  / \
      2   3 4  5'''
a = Node(10)
b = Node(6)
c = Node(7)
b.left = Node(2)
b.right = Node(3)
c.left = Node(4)
c.right = Node(5)

a.left = b
a.right = c
a.print_all()
