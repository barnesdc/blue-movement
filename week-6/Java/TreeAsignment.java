import java.util.LinkedList;
public class TreeAsignment{

  public static int MaxDifference(BinaryTree bt){
    LinkedList<Integer> differences=new LinkedList();
    Subtract(bt.root, bt.root.left, differences);
    int max=0;
    for (Integer i: differences){
      int d=i.intValue();
      if(d>max){
        max=d;
      }
    }
    return max;
  }


  public static void  Subtract(Node parent, Node child, LinkedList<Integer> ls){
     if(child==null || parent==null){return;}
     ls.add(parent.data-child.data);
     Subtract(parent,parent.right,ls);
     Subtract(child,child.left,ls);
  }
    




public static void printRoutes(BinaryTree bt){
    LinkedList<Integer> ls= new LinkedList();
    HandleNode(bt.root,ls);
  } 


  public static void  HandleNode(Node node,LinkedList<Integer> list){

if(node== null){return;}
list.add(node.data);

HandleNode(node.right,list);
HandleNode(node.left,list);
if (node.right==null &&  node.left==null){
  for (int i=list.size()-1;i>0;i--){
    System.out.print(list.get(i));
    System.out.print("->");
  }
  System.out.print(list.get(0));
  }
  System.out.println();
list.removeLast();
}


public static void Flip(Node n){
    if(n==null){
      return;
    }
   Node l=n.left,r=n.right;
   n.right=l;
   n.left=r;
   Flip(n.right);
   Flip(n.left);
  } 


  
    
  public static void main(String[] args) {
    
    BinaryTree tb = new BinaryTree(1);
		tb.root.left=new Node(2);
		tb.root.right=new Node(3);
		tb.root.left.left=new Node(4);
		tb.root.left.right=new Node(5);
		tb.root.right.left=new Node(6);
		tb.root.right.right=new Node(7);
		tb.root.right.left.left=new Node(8);
		tb.root.right.left.right=new Node(9);

    printRoutes(tb);

  }
}


class Node{

int data;
public Node left,right;
public Node(int dt){
  this.data=dt;
}
public Node(){
  
}
public void add(int data){


 if(this.data>data){
        if(left==null){
          left=new Node();
          left.data=data;
        
        }
        else{
          left.add(data);
        }
  }else{
   if(right==null){
          right=new Node();
          right.data=data;
        
        }
        else{
          right.add(data);
  }
}

}

}






class BinaryTree{

Node root;

public BinaryTree(int data){
  root=new Node();
  root.data=data;

}

}