import java.util.*;

public class Netters_TreeMirror{

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

        public static void Mirror(Node node){
            if(node == null)
                return;
            
                node.left = right;
                node.right = left;

            Mirror(node.left);
            Mirror(node.right);
            
        }

        public static void main(String[] args){
        
                BinaryTree tree = new BinaryTree(6);
                tree.left = new BinaryTree(3);
                tree.right= new BinaryTree(8);
                tree.left.left = new BinaryTree(2);
                tree.left.right = new BinaryTree(4);
                tree.right.left = new BinaryTree(7);
                
            
              tree.printPaths(tree.root);
            
              
        }
}