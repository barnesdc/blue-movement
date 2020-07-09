import java.util.*;
import java.io.*;

/*
Find Maximum Difference Between a Node and its Descendants in a Binary Tree. https://ibb.co/563hJSG

Write an algorithm to print leaf to root path for every leaf node of the binary tree. https://ibb.co/G7sZnDZ

Write an algorith to convert a tree to its mirror. https://ibb.co/H40dhCt
*/

public class Amaya_Howard_Carswell{
    //Variables for the max difference function
    static int max_diff = 0;

    // Generic node class
    public static class Node{
        int val;
        Node left;
        Node right;

        Node(int x){
            val = x;
            left = null;
            right = null;
        }
    }

    // A helper recursive function
    // Will use DFS in a preorder traversal
    public static void maxDiff(Node root, int min, int max){
        // Base case for when we've gone past the leaf nodes
        if (root == null)
            return;

        // Compares the current root val to the max and min vals
        if (root.val < min)
            min = root.val;
        else if (root.val > max)
            max = root.val;

        int diff = max - min;

        // If diff is greater than max_diff, max_diff is set to diff
        max_diff = (diff > max_diff) ? diff : max_diff;

        // Traverses through the rest of the tree
        maxDiff(root.left, min, max);
        maxDiff(root.right, min, max);

    }
    public static int maxDifference(Node root){
        // Calls helper function with root's val as first min and max
        // Alters the max_diff then returns
        maxDiff(root, root.val, root.val);
        return max_diff;
    }

    public static void printPath(List<Integer> path){
        Collections.reverse(path);
        for (int i : path)
            System.out.print(i + "->");
        System.out.println("");
    }

    // Helper function for findPaths
    // Also uses a preoder traversal
    public static void findPath(Node root, List<Integer> path){
        // Just a check to check the original root isn't null
        if (root == null)
            return;

        path.add(root.val);

        // We've reached a leaf node
        // Then prints the path
        if (root.left == null && root.right == null){
            printPath(path);
            return;
        }

        // Continues to traverse the tree with new LinkedList containing
        // the elements from the previous path to keep track of previous elements
        findPath(root.left, new LinkedList<>(path));
        findPath(root.right, new LinkedList<>(path));

    }

    // Creates a LinkedList path then
    // Calls the helper function
    public static void findPaths(Node root){
        List<Integer> path = new LinkedList<>();
        findPath(root, path);
    }

    // Helper function for the mirror function
    public static void inorder(Node root){
        if (root == null)
            return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);

    }

    // Uses swap function to switch pointers
    // Then recursively iterates through the rest of the tree
    public static Node mirrorTree(Node root){
        if (root != null){
            swap(root);
            mirrorTree(root.left);
            mirrorTree(root.right);
        }

        return root;
    }

    // Helper function to swap pointers to left and right node
    public static void swap(Node root){
        Node temp = root.left;
        root.left = root.right;
        root.right = temp;
    }

    public static void main(String[] args){
        Node root = new Node(6);                                     // 6
        root.left = new Node(3);                                   // 3   7
        root.right = new Node(7);                                // 4  2 0  8
        root.left.left = new Node(4);                             //       5
        root.left.right = new Node(2);
        root.right.left = new Node(0);
        root.right.right = new Node(8);
        root.right.right.left = new Node(5);

        System.out.print("The inorder traversal of the tree is ");
        inorder(root);
        System.out.println("");

        // Right Answer = 7
        System.out.println("The max difference is " + maxDifference(root));
        System.out.println("");

        // Right Answer = 4->3->6, 2->3->6, 0->7->6, 5->8->7->6
        System.out.println("The leaf node paths are ");
        findPaths(root);
        System.out.println("");

        System.out.print("The tree after mirroring is ");
        inorder(mirrorTree(root));


    }

}
