
/**
 * TreeNode class.
 */
class TreeNode<T> {
    int value;
    TreeNode<T> left;
    TreeNode<T> right;
 
    TreeNode(int val) {
        this.value = val;
        right = null;
        left = null;
    }
}
/**
 * This class handles all the Tree functions.
 */
class AnthoniaUjuDuru {
    
    public static int maxDifference(TreeNode<Integer> tree, int diff, int rootVal) {
        if (tree == null) {  // base case; tree is null
            return diff;
        } 

        // loop through left child for max dist root val
        int left = maxDifference(tree.left, diff, rootVal);

        // loop through right child for max dist root val
        int right = maxDifference(tree.right, diff, rootVal);

        // get max difference between of left and right 
        diff = Math.max((rootVal - left), (rootVal- right));

        // pick the number with the max dist of two
        return diff;
    } 


    /**
     * 
     * Function to mirror tree.
     * @param tree
     * @return reversed tree
     */
    public static TreeNode<Integer> mirrorTree(TreeNode<Integer> tree) {
        if (tree == null) { // base case if tree is null
            return null;
        }
        // create temp nodes to recursively store the left and right
        TreeNode<Integer> l = mirrorTree(tree.left);
        TreeNode<Integer> r = mirrorTree(tree.right);

        // swap the left and right values
        tree.left = r;
        tree.right = l;

        return tree;
    }

    /**
     * Prints out content of tree preorder under Depth First Search.
     * @param tree
     */
    public static void printTree(TreeNode<Integer> tree) {
        if (tree != null) {
            System.out.println(tree.value);
            printTree(tree.left);
            printTree(tree.right);
        }
    }
    /**
     * 
     * @param args
     */
    public static void main(String[] args) {
        /* 
         *        6
         *       / \
         *      3   8
         *         / \
         *        2   4
         *       / \
         *      1   7
         *  
         */
    
        TreeNode<Integer> tree = new TreeNode<Integer>(6);
        tree.value = 6;
        tree.left = new TreeNode<Integer>(3);
        tree.right = new TreeNode<Integer>(8);
        tree.right.left = new TreeNode<Integer>(2);
        tree.right.right = new TreeNode<Integer>(4);
        tree.right.left.left = new TreeNode<Integer>(1);
        tree.right.left.right = new TreeNode<Integer>(7);

        //printTree(tree);
        System.out.println();
        System.out.println(maxDifference(tree, Integer.MIN_VALUE, tree.value));
        //TreeNode<Integer> flipped = mirrorTree(tree);
        //printTree(flipped);
    }
}