class LinkedList { 
  
    //static Node head; 
  
    static class Node { 
  
        char data; 
        Node next; 
  
        Node(char d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
  
    public static Node reverseLL(Node a){

        StringBuilder temp = new StringBuilder();

        while(a.next != null){
            temp.append(a.data);
        }

        temp.reverse();
        String s = temp.toString();
        Node t = new Node ();
        Node head = t;

        for(int i = 0;i<s.length();i++){
            t.data = s.charAt(i);
            t = t.next();
        }

        return head;

    }

    public static Node createList(String s){
        Node list =  new Node();
        Node list2 = list;
        for (int i = 0;i<s.length();i++){
            list.data = s.charAt(i);
            list = list.next;
        }
        return list2;
    }

    public static printList(Node a){
        while(a.data){
            System.out.println(a.data);
            a = a.next;
        }
    }
    public static void main(String[] args) 
    { 
        String s = "hello";
        //System.out.println("hi");
        Node list = createList(s);
        list = reverseLL(list);
        printList(list);      

      
    } 
} 