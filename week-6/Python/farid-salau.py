# question one
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def helper(root, ret):
    if not root:
        return 2147483648, ret

    if not root.left and not root.right:
        return root.val, ret

    val1, ret = helper(root.left, ret)
    val2, ret = helper(root.right, ret)

    v = min(val1, val2)

    ret = max(ret, root.val - v)

    return min(v, root.val), ret


def max_difference(root):
    ret = -2147483648
    x, ret = helper(root, ret)
    return ret


root = TreeNode(7)
root.left = TreeNode(2)

root.left.left = TreeNode(0)
root.left.right = TreeNode(5)
root.left.right.left = TreeNode(3)
root.left.right.right = TreeNode(6)

print(max_difference(root))


############ END QUESTION ONE #############
# question 2

def p_helper(r: TreeNode, path: list, length: int):
    if r:
        if len(path) > length:
            path[length] = r.val
        else:
            path.append(r.val)

        length += 1

        if not r.left and not r.right:
            p(path, length)
        else:
            p_helper(r.left, path, length)
            p_helper(r.right, path, length)


def p(a, b):
    for i in a[: b]:
        print(i, end="\n")


def paths(r):
    p_helper(root, [], 0)

############ END QUESTION TWO #############

# question 3


def to_mirror(r: TreeNode):
    if r:
        t = r
        to_mirror(r.left)
        to_mirror(r.right)
        t = r.left
        r.left = r.right
        r.right = t


def pt(r: TreeNode):
    if r:
        pt(r.left)
        print(r.val)
        pt(r.right)


pt(root)
p(root)
