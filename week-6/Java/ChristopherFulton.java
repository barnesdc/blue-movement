


  class Trees{
     

class Node{
    Node left;
    Node right;
    int data;
    
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

// A Java program to introduce Binary Tree 

 static void getDistanceToRoot(Node node,int counter) {
    if (node == null) {
        counter = 0;
        return;
    }
    counter++;

    getDistanceToRoot(node.left,counter);
     System.out.printf("%s ", node.data + ": " + (counter-1));
    getDistanceToRoot(node.right,counter);
}

public static void main(String[] args) {
    Node root = new Trees().new Node(6);
    root.left =new Trees(). new Node(3);
    root.right =new Trees(). new Node(8);
    root.left.left =new Trees(). new Node(2);
    root.left.right = new Trees(). new Node(4);
    root.right.left =  new Trees().new Node(1);
    root.right.right =new Trees(). new Node(7);
    getDistanceToRoot(root,0);
}
   
}	
   
    
