public class cordero { 
  //null pointer exception, not sure how to fix need more time to troubleshoot
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
        Node t = new Node ('c');
        Node head = t;

        for(int i = 0;i<s.length();i++){
            t.data = s.charAt(i);
            t = t.next;
        }

        return head;

    }

    public static Node createList(String s){
        Node list = new Node('e');
        Node list2 = list;
        for (int i = 0;i<s.length();i++){
            list.data = s.charAt(i);
            list = list.next;
        }
        return list2;
    }

    public static void printList(Node a){
        while(a.next != null){
            System.out.println(a.data);
            a = a.next;
        }
    }
    public static void main(String[] args) 
    { 
        String s = "hello";
        Node list = createList(s);
        list = reverseLL(list);
        printList(list);      

      
    } 
} 