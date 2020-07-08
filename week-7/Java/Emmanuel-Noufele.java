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

public class maximumDifference {
	static int maxDiff = Integer.MIN_VALUE;
	public static void findMaxDifference(TreeNode root, int min, int max) {
        if(root == null) {
            return;
        }
        if(root.val < min) {
            min = root.val;
        }
        if(root.val > max) {
            max = root.val;
        }
        if(maxDiff < max - min) {
            maxDiff = max - min;
        }
        findMaxDifference(root.left, min, max);
        findMaxDifference(root.right, min, max);
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TreeNode root = new TreeNode(6, new TreeNode(3, null, null), new TreeNode(8, new TreeNode(2, new TreeNode(1), new TreeNode(7)), new TreeNode(4, null, null)));
		findMaxDifference(root, Integer.MAX_VALUE, Integer.MIN_VALUE);
		System.out.println("The maximum difference between a node and it's descendant is " + maxDiff);
	}
}


package hackerrsnk;

import java.util.Stack;

public class printAllLeafToRoot {
	
	public static boolean isLeaf(TreeNode node) {
		
		// Check if the right child and the left child are both null
		if(node.left == null && node.right == null) {
			return true;
		}
		return false;
	}
	
	public static void printCurrentPath(Stack <Integer> stack) {
		
		for(int i = stack.size() - 1; i >= 0; i--) {
			System.out.print(stack.get(i));
			if(i > 0) {
				System.out.print(" -> ");
			}
		}
		System.out.println();
	}
	
	public static void printAllPaths(TreeNode node, Stack<Integer> stack) {
		
		if(node == null) {
			return;
		}
		
		// add the current node to the stack
		stack.add(node.val);
		
		// Check if the current node is a leaf node
		if(isLeaf(node)) {
			printCurrentPath(stack);
		}
		
		// recurse for left and right subtree
		printAllPaths(node.left, stack);
		printAllPaths(node.right, stack);
		
		// This will remove the current node after we are done with the left and right subtree
		stack.pop();
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(4, null, null), new TreeNode(5, null, null)), 
				new TreeNode(3, new TreeNode(6, new TreeNode(8, null, null), new TreeNode(9, null, null)), new TreeNode(7, null, null)));
		Stack <Integer> stack = new Stack<Integer>();
		
		// print all paths from leaf to root
		printAllPaths(root, stack);
		
	}

}

