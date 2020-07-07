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
