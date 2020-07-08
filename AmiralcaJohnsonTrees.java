import java.util.*;

class AmiralcaJohnsonTrees {
    
    // Store binary tree node
    class Node{
        int data;
        Node left = null;
        Node right = null;
        Node(int data){
            this.data = data;
        }
    }
    public static void main(String args[]){
        // Prompt 1: Max Diff. Between a Node & its Descendants in a Binary Tree
        // Example binary tree input
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(7);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        root.right.left = new Node(4);
        root.right.right = new Node(6);
        // Print max diff. 
        System.out.print(maxDiff(root)); // output = 6 (7 - 1 = 6)

        // Prompt 2: Algorithm to Print Leaf to Root Path for Every Leaf Node in Binary Tree
        // Example binary tree input from Prompt 1
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(7);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        root.right.left = new Node(4);
        root.right.right = new Node(6);
        // Print leaf to root path in array list; output = Left:[1,2,4]; [2,4]; [3,2,4]; Right:[4,7,4]; [7,4]; [6,7,4]

        // Prompt 3: Algorithm to Convert a Tree to its Mirror
        // Example binary tree input from Prompt 1
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(7);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        root.right.left = new Node(4);
        root.right.right = new Node(6);
        // Print mirror image of binary tree; output = 4764231
    }
    // Prompt 1: Max Diff. Between a Node & its Descendants in a Binary Tree
    // Max diff. function
    public static void int maxDiff(Node root, int diff){
        // If binary tree is empty, return "empty"
        if(root == null){
            System.out.println("Binary tree is empty");
        }
        // Use recursion to move left and right in the binary tree subtree. Need to find min and max diff in left and right of binary tree
        // Find max diff between current node and its descendants in binary tree
            // root - min value on the left and right of binary tree
        // Update max diff by comparing previous diff to current diff
        // Return max diff
    }
    // Prompt 2: Algorithm to Print Leaf to Root Path for Every Leaf Node in Binary Tree
    // Find paths from leaf node to root function
    public static void LeafToRoot(){
        // If binary tree is empty, return "empty"
        if(root == null){
            System.out.println("Binary tree is empty");
        }
        // If leaf node is found, print path from leaf to root
        // Use recursion to move left and right in the binary tree subtree
        // Return leaf to root path for all leaf nodes
    }
    // Prompt 3: Algorithm to Convert a Tree to its Mirror
    // Swap left and right subtree function (Root stays the same)
    // Convert binary tree to mirror image function
    public static void mirrorImage(Node root){
        // If binary tree is empty, return "empty"
        if(root == null){
            System.out.println("Binary tree is empty");
        }
        // Convert left subtree of binary tree
        // Convert right subtree of binary tree
        // Use swap function to swap left and right subtrees
        // Return mirror image of binary tree
    }
}