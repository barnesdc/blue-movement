
public class firaol_woldemariam{
    
    Node root;
    
    public static void main(String args[]){
        
        firaol_woldemariam tree = new firaol_woldemariam();
        
        tree.maxDiff(tree.root);
    }
    
    
    public int maxDiff(Node root)
    {
        Ref ref = new Ref();
        maxDifference(root, ref);
        
        return ref.r;
    }
    
    private int maxDifference(Node n, Ref ref)
    {
        if(n == null)
        {
            return Integer.MAX_VALUE;
        }
        if(n.left == null && n.right == null)
        {
            return n.key;
        }
        
        int value = Math.min(maxDifference(n.left, ref), maxDifference(n.right, ref));
        
        ref.r = Math.max(ref.r, n.key - value);
        
        return Math.min(value, n.key);
    }
    
    class Ref{
        int r = Integer.MIN_VALUE;
    }
    
    class Node{
        int key;
        Node left;
        Node right;
        
        public Node(int key)
        {
            this.key = key;
            left = null;
            right = null;
        }
    }
}