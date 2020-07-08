import java.util.*;

class TreeNode {
	 int val;
	 TreeNode left;
	 TreeNode right;
	 TreeNode() {}
	 TreeNode(int val) { this.val = val; }
	 TreeNode(int val, TreeNode left, TreeNode right) {
		 this.val = val;
		 this.left = left;
		 this.right = right;
	}
}

public class Week6 {

	/*
	 * PROMPT 1: Find Maximum Difference Between a Node and its Descendants in a Binary Tree.
	 * 1. You need to find the maximum difference between a parent and all of it's nodes
	 * 2. Then compare that maximum difference to the main maximum difference in the whole tree
	 */
	
	//finds the maxDifference between a parent and all of it's ancestors
    private int maxParentAncestorDiff(TreeNode parent, TreeNode ancestor, int maxDifference){
        if(ancestor == null){
            return maxDifference;
        } else{
            int difference = Math.abs(parent.val - ancestor.val); //difference between current ancestor and parent node
            maxDifference = Math.max(maxDifference, difference); //change maxDifference if the difference calculated is greater
            
            //find the maxDifference in the left subtree of currentAncestor
            int maxDifferenceLeft = maxParentAncestorDiff(parent, ancestor.left, maxDifference); 
            //find the maxDifference in the right subtree of currentAncestor
            int maxDifferenceRight = maxParentAncestorDiff(parent, ancestor.right, maxDifference);
            
            //sets maxDifference to the greatest maxDifference found in both left and right subtree
            maxDifference = Math.max(maxDifferenceLeft, maxDifferenceRight); 
            return maxDifference; 
        }
    }
    
    //find the maxDifference of the entire tree
    private int maxAncestorDiff(TreeNode root, int maxDifference) {
        if(root == null){
            return maxDifference;
        }
        else{
            //find the maxDifference between the current root and all of it's ancestors
            maxDifference = maxParentAncestorDiff(root, root, maxDifference);
            
            //go to the left and right subtrees and find the maxDifference in each subtree
            int maxDifferenceLeft = maxAncestorDiff(root.left, maxDifference);
            int maxDifferenceRight = maxAncestorDiff(root.right, maxDifference);
            
            maxDifference = Math.max(maxDifferenceLeft, maxDifferenceRight);
            return maxDifference;
        }
    }
    
    public int maxAncestorDiff(TreeNode root) {
        return maxAncestorDiff(root, 0);
    }
	
	
	/*
	* PROMPT 2: Write an algorithm to print leaf to root path for every leaf node of the binary tree
    * Output: List of strings. Each string is a path from a root to a node
    */
    public void binaryTreePaths(TreeNode root, String path, List<String> paths){
        if(root != null){
            if(root.left != null || root.right != null){
                if(path.equals("")){//if you are at the root of the tree
                    binaryTreePaths(root.left, root.val + path, paths);
                    binaryTreePaths(root.right, root.val + path, paths);
                }
                else{
                    binaryTreePaths(root.left, root.val + "->" + path, paths);
                    binaryTreePaths(root.right, root.val + "->" + path, paths); 
                }
            }else{
                System.out.println(root.val + "->" + path);
                paths.add(path + root.val);
            }
        }
    }
    
    
    /*
     * PROMPT 3: Write an algorithm to convert a tree to its mirror.
     * 1. Root val stays same
     * 2. Swap left and right nodes of root
     * 3. Go left
     * 4. Swap left and right nodes of left node
     * 5. Go right
     * 6. Swap left and right nodes of right node.
     * 
     * 1. Create a new tree.
     * 2. Set the root of original tree to new tree
     * 3. Get to a node and swap the left and right nodes
     */
    public void swapNodesInTree(TreeNode root){
        if(root != null){
            TreeNode temp = root.right;
            root.right = root.left;
            root.left = temp;
            swapNodesInTree(root.left);
            swapNodesInTree(root.right);
        }
    }
    
    public TreeNode invertTree(TreeNode root) {
        swapNodesInTree(root);
        return root;
    }
}
