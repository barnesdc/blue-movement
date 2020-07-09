
import java.util.*;

public class Netters_TreesDiff{

    class Node{
        int data;
        Node left;
        Node right;
    
        //constructor
        public Node(int data){
          this.data = data; 
        }
      }
    
        class Res  
        { 
            int r = Integer.MIN_VALUE; 
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
       
        /* Recursive function to calculate maximum ancestor-node 
           difference in  binary tree. It updates value at 'res' 
           to store the result.  The returned value of this function 
           is minimum value in subtree rooted with 't' */
        int maxDiffUtil(Node t, Res res)  
        { 
            /* one child node case*/
            if (t == null) 
                return Integer.MAX_VALUE; 
               
            /* leaf node case */
            if (t.left == null && t.right == null) 
                return t.data; 
       
            /* Recursively calling left and right subtree 
               for minimum value  */
            int val = Math.min(maxDiffUtil(t.left, res), 
                    maxDiffUtil(t.right, res)); 
       
            /* Update res*/
            res.r = Math.max(res.r, t.data - val); 
       
            /* Returning minimum value got so far */
            return Math.min(val, t.data); 
        } 
       
        /* This function mainly calls maxDiffUtil() */
        int maxDiff(Node root)  
        { 
            Res res = new Res(); 
            maxDiffUtil(root, res); 
       
            return res.r; 
        } 
          
    }     
    
      public static void main(String[] args) {
        BinaryTree tree = new BinaryTree(6);
        tree.left = new BinaryTree(3);
        tree.right= new BinaryTree(8);
        tree.left.left = new BinaryTree(2);
        tree.left.right = new BinaryTree(4);
        tree.right.left = new BinaryTree(7);
        
    
        System.out.println("Max difference is" + tree.maxDiff(tree.root));
    
      }

}
