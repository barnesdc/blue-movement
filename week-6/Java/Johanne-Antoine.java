
class BinaryTree {
    static class Node {
        int key;
        Node left, right;
        public Node(int item) {
            this.key = item;
            left = right = null;
        }
    
    }
    Node root;
    BinaryTree(int key) { 
        root = new Node(key); 
    } 
  
    BinaryTree()  { 
        root = null; 
    } 
    
    static int maxDiff(Node root) {
        // assume difference can be positive or negative
        int diff = 0;
        if (root.left == null && root.right == null || root == null) {
            return diff;
        } else {
            //postorder iterator
            //how to switch to right
            Node trav = root;
            Node parent = root;
            while (trav.left != null || trav.right != null)
            {    
                if (trav.left != null) {
                    parent = trav;
                    trav = trav.left;
                    diff = Math.max(diff, Math.abs(root.key - trav.key));
                    diff = Math.max(diff, maxDiff(trav));
                } else if (trav.right != null) {
                    trav = trav.left;
                    diff = Math.max(diff, Math.abs(root.key - trav.key));
                    diff = Math.max(diff, maxDiff(trav));
                }

            }
        }
        return diff;
    }
    static void printLeafToRoot(Node root, StringBuilder tree) {
        if (root.left != null) {
            StringBuilder newTree = new StringBuilder(tree);
            newTree.insert(0, "->" + root.key);
            printLeafToRoot(root.left, newTree);
        }
        if (root.right != null) {
            StringBuilder newTree = new StringBuilder(tree);
            newTree.insert(0, "->" + root.key);
            printLeafToRoot(root.right, newTree);
        }
        if (root.left == null && root.right == null) {
            StringBuilder newTree = new StringBuilder(tree);
            newTree.insert(0, root.key);
            System.out.println(newTree);
        }
    }

    static Node mirror(Node root) {
        Node m = root;
        if (m == null) {
            return m;
        }
        if (root.left != null || root.right != null) {
            Node temp = root.left;
            root.left = root.right;
            root.right = temp;
            root.left = mirror(root.left);
            root.right = mirror(root.right);
        }
        return m;
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree(1);
        bt.root.left = new Node(2);
        bt.root.right = new Node(3);
        bt.root.left.left = new Node(4);
        Node five = new Node(5);

        StringBuilder s = new StringBuilder();
        printLeafToRoot(bt.root, s);
        Node newTree = mirror(bt.root);
        printLeafToRoot(newTree, s);
        System.out.println(maxDiff(bt.root));
    }
    
}

