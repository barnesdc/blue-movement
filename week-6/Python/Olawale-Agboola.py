# To create a new node
def __init__(self, key):
    self.key = key
    self.left = None
    self.right = None

def maxcapacity(t, res):

    if (t == None):
        return _MAX, res



       #to call the left and right subtree using recursion
    a, res = maxcapacity(t.left, res)
    b, res = maxcapacity(t.right, res)
    val = min(a, b)


    res = max(res, t.key - val)

    return min(val, t.key), res



def maxDifference(root):
    # Initialising result with minimum value
    res = _MIN
    x, res = maxcapacity(root, res)
    return res



def inorder(root):
    if (root):
        inorder(root.left)
        prf("%d ", root.key)
        inorder(root.right)


class newNode:
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



def inOrder(node):
    if (node == None):
        return

    inOrder(node.left)
    print(node.data, end=" ")
    inOrder(node.right)

if __name__ == "__main__":
    root = newNode(1)
    root.left = newNode(2)
    root.right = newNode(3)
    root.left.left = newNode(4)
    root.left.right = newNode(5)

    inOrder(root)

    mirror(root)

    inOrder(root)


