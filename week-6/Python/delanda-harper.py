class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def maxDifference(root, diff=float('-inf')):
    
    if root is None:
        return float('inf'), diff

    left, diff = maxDifference(root.left, diff)
    right, diff = maxDifference(root.right, diff)

    d = root.data - min(left, right)

    diff = max(diff, d)

    return min(min(left, right), root.data), diff


if __name__ == '__main__':

    
    root = Node(10)
    root.left = Node(6)
    root.right = Node(3)
    root.right.left = Node(5)
    root.right.right = Node(2)
    root.right.left.left = Node(1)
    root.right.left.right = Node(4)

    print(maxDifference(root)[1])
