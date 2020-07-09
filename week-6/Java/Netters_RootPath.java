import java.util.*;

public class Netters_RootPath {
    class Node{
        int data;
        Node left;
        Node right;
    
        //constructor
        public Node(int value){
          data = value;
          left = null;
          right = null; 
        }
    }

        //insert method
        public void insert(int value){
          if (value <= data){
            if(left == null){
              left = new Node(value);
            }
            else{
              left.insert(value);
            }
          }
    
          else{
            if(right == null){
              right = new Node(value);
            }
            else{
              right.insert(value);
            }
          }
    
        }
  
        //root node in middle
        public void InOrder(){
          if(left != null){
            left.InOrder();
          }
          System.out.println(data);
          if(right != null){
            right.InOrder();
          }
        }
    
        //root node first
        public void PreOrder(){
          System.out.println(data);
          if(left != null){
            left.PreOrder();
          }
          if(right != null){
            right.PreOrder();
          }      
        }
    
        //root node last
        public void PostOrder(){
          if(left != null){
            left.PostOrder();
          }
          if(right != null){
            right.PostOrder();
          } 
          System.out.println(data);      
        }

    public class BinaryTree  
    {
      Node root;
       
    /*Given a binary tree, print out all of its root-to-leaf 
      paths, one per line. Uses a recursive helper to do  
      the work.*/
    void printPaths(Node node)  
    { 
        int path[] = new int[1000]; 
        printPathsRecur(node, path, 0); 
    } 
   
    /* Recursive helper function -- given a node, and an array 
       containing the path from the root node up to but not  
       including this node, print out all the root-leaf paths.*/
    void printPathsRecur(Node node, int path[], int pathLen)  
    { 
        if (node == null) 
            return; 
   
        /* append this node to the path array */
        path[pathLen] = node.data; 
        pathLen++; 
   
        /* it's a leaf, so print the path that led to here  */
        if (node.left == null && node.right == null) 
            printArray(path, pathLen); 
        else 
        { 
            /* otherwise try both subtrees */
            printPathsRecur(node.left, path, pathLen); 
            printPathsRecur(node.right, path, pathLen); 
        } 
    } 
   
    /* Utility function that prints out an array on a line. */
    void printArray(int ints[], int len)  
    { 
        int i; 
        for (i = 0; i < len; i++)  
        { 
            System.out.print(ints[i] + " "); 
        } 
        System.out.println(""); 
    } 

  }

public void traverseLevelOrder() {
    if (root == null) {
        return;
    }
 
    Queue<Node> nodes = new LinkedList<>();
    nodes.add(root);
 
    while (!nodes.isEmpty()) {
 
        Node node = nodes.remove();
 
        System.out.print(" " + node.value);
 
        if (node.left != null) {
            nodes.add(node.left);
        }
 
        if (node.right != null) {
            nodes.add(node.right);
        }
    }
}

      public static void main(String[] args) {
        BinaryTree tree = new BinaryTree(6);
        tree.left = new BinaryTree(3);
        tree.right= new BinaryTree(8);
        tree.left.left = new BinaryTree(2);
        tree.left.right = new BinaryTree(4);
        tree.right.left = new BinaryTree(7);
        
    
      tree.printPaths(tree.root);
    
      }
}