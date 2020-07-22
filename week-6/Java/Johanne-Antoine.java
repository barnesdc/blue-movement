
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
    static int findMax(Node root) {
        if (root == null) {
            return -1;
        } else {
            int r = root.key;
            if (root.left == null && root.right == null) {
                return r;
            } else {
                r = Math.max(r, findMax(root.left));
                r = Math.max(r, findMax(root.right));
            }
            return r;
        }
        
    }
// helper method
    static int findMin(Node root) {
        if (root == null) {
            return -1;
        } else {
            int r = root.key;
            if (root.left == null && root.right == null) {
                return r;
            } else {
                r = Math.min(r, findMin(root.left));
                r = Math.min(r, findMin(root.right));
            }
            return r;
        }
        
    }
    static int maxDiff(Node root) {
        // assume difference uses absolue value
        int diff = 0;
        /* if (root.left == null && root.right == null || root == null) {
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
        } */
        if (root == null) {
            return -1;
        } else {
            int min = findMin(root);
            int max = findMax(root);
            diff = Math.max(Math.abs(root.key-min), Math.abs(root.key-max));
            diff = Math.max(diff, maxDiff(root.left));
            diff = Math.max(diff, maxDiff(root.right));
        }
        
        
        return diff;
    }
    //print from leaf to root
    static void printLeafToRoot(Node root, StringBuilder path) {
        if (root.left != null) {
            StringBuilder leftPath = new StringBuilder(path);
            leftPath.insert(0, "->" + root.key);
            printLeafToRoot(root.left, leftPath);
        }
        if (root.right != null) {
            StringBuilder rightPath = new StringBuilder(path);
            rightPath.insert(0, "->" + root.key);
            printLeafToRoot(root.right, rightPath);
        }
        //when you reach a leaf node
        if (root.left == null && root.right == null) {
            StringBuilder newTree = new StringBuilder(path);
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
            // switch children
            Node temp = root.left;
            root.left = root.right;
            root.right = temp;
            // recursion
            root.left = mirror(root.left);
            root.right = mirror(root.right);
        }
        return m;
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree(6);
        Node three = new Node(3);
        Node eight = new Node(5);
        Node two = new Node(2);
        Node four = new Node(4);
        Node one = new Node(1);
        Node seven = new Node(7);
        bt.root.left = three;
        bt.root.right = eight;
        eight.left = two;
        eight.right = four;
        two.left = one;
        two.right = seven;
        StringBuilder s = new StringBuilder();
        printLeafToRoot(bt.root, s);
        Node newTree = mirror(bt.root);
        printLeafToRoot(newTree, s);
        System.out.println("Maximum: " + findMax(bt.root));
        System.out.println("Minimum: " + findMin(bt.root));
        System.out.println("Maximum difference: " + maxDiff(bt.root));
    }
    
}

