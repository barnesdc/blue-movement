class LinkedCharList {
    Node head;
    static class Node {
        char data;
        Node next;
        Node prev;
        Node (char d) {
            data = d;
            next = null;
            prev = null;
        }
    }
    public void insert(Node nd) {
        if (this.head == null) {
            this.head = nd;
        } else {  
             Node pointer = this.head;
            while (pointer.next != null) {
                pointer = pointer.next;
            }
            pointer.next = nd;
            nd.prev = pointer;
        }
    }
    LinkedCharList(String s) {
        for (int i = 0; i < s.length(); i++) {
            this.insert(new Node(s.charAt(i)));
        }
    }

    public static void printList(Node head) {
        Node pointer = head;
        while (pointer != null) {
            System.out.print(pointer.data);
            pointer = pointer.next;
        }
    }

    public Node reverse(Node n) {
        Node prev = null; 
        Node current = n; 
        Node next = null; 
        while (current != null) { 
            next = current.next; 
            current.next = prev; 
            prev = current; 
            current = next; 
        } 
        n = prev; 
        return n; 
    }

    public static Node reverseSentence(LinkedCharList cl) {
        Node n = cl.reverse(cl.head);
        LinkedCharList result = new LinkedCharList("");
        LinkedCharList temp = new LinkedCharList("");
        Node p = n;
        while (p != null) {
            if (p.data == ' ') {
                temp.head = temp.reverse(temp.head);
                result.insert(temp.head);
                result.insert(new Node(p.data));
                temp = new LinkedCharList("");
            } 
            else {
                temp.insert(new Node(p.data));
                if (p.next == null) {
                    temp.head = temp.reverse(temp.head);
                    result.insert(temp.head);
                }
            }
            p = p.next;
        }
        return result.head;
    }
    public static void main(String[] args) {
        LinkedCharList charList = new LinkedCharList("I love Geeks for Geeks");
        //printList(charList.reverse(charList.head));
        printList(reverseSentence(charList));
    }
}