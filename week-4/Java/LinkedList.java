class LinkedList {
    Node head;
    static class Node {
        int data;
        Node next;
        Node prev;
        Node (int d) {
            data = d;
            next = null;
            prev = null;
        }
    }
    public void insert(Node n) {
        if (this.head == null) {
            this.head = n;
        } else {  
             Node pointer = this.head;
            while (pointer.next != null) {
                pointer = pointer.next;
            }
            pointer.next = n;
            n.prev = pointer;
        }
    }
    LinkedList(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            this.insert(new Node(arr[i]));
        }
    }
    public static void main(String[] args) {
        LinkedList llist = new LinkedList(new int[]{9, 9, 9});
        LinkedList llist2 = new LinkedList(new int[]{1, 0, 0, 1});
        LinkedList sumList = new LinkedList(new int[]{});
        sumList.head = add(llist, llist2);

        printList((sumList.head));
    }

    public static void printList(Node head) {
        Node pointer = head;
        while (pointer != null) {
            System.out.print(pointer.data + " ");
            pointer = pointer.next;
        }
    }
    public static Node add(LinkedList l1, LinkedList l2) {
        LinkedList result = new LinkedList(new int[] {});
        Node p1 = l1.reverse(l1.head);
        Node p2 = l2.reverse(l2.head);
        int carry = 0;
        while (p1 != null && p2 != null) {
            int digit = (p1.data + p2.data + carry) % 10;
            carry = (p1.data + p2.data + carry) / 10;
            Node n = new Node(digit);
            result.insert(n);
            p1 = p1.next;
            p2 = p2.next;
        }
        if (p2 != null) {
            while (p2 != null) {
                int digit = (p2.data + carry) % 10;
                carry = (p2.data + carry) / 10;
                result.insert(new Node(digit));
                p2 = p2.next;
            }
        } else if (p1 != null) {
            while (p1 != null) {
                int digit = (p1.data + carry) % 10;
                carry = (p1.data + carry) / 10;
                result.insert(new Node(digit));
                p1 = p1.next;
            }
        }
        if (carry != 0) {
            result.insert(new Node(carry));
        }
        return result.reverse(result.head);
    }
    // reverses the node order.
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
}