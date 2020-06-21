import java.util.*;
import java.io.*;

/*
1.   Given two numbers represented by two linked lists, write a function that returns sum list. 4
     The sum list is linked list representation of addition of two input numbers.

2.   Given a Linked List which represents a sentence S such that each node represents a letter,
     the task is to reverse the sentence without reversing individual words.
*/

public class Amaya_Howard_Carswell{

    // Generic node class
    public static class Node{
        Object val;
        Node next;

        Node(Object x){
            this(x, null);
        }

        // Overloaded method
        Node(Object x, Node nx){
            val = x;
            next = nx;
        }
    }

    public static Node reverseList(LinkedList<Node> list){
        Node cur = list.get(0);
        Node nxt;
        Node prv = null;
        Node head = null;

        // Keeps track of the previous and next nodes
        // Sets the next node to the stored previous value
        // Then sets the current node to the stored next value
        while (cur != null){
            if (cur.next == null){
                head = cur;
            }
            nxt = cur.next;
            cur.next = prv;
            prv = cur;
            cur = nxt;
        }

        return head;
    }

    public static Node addList(Node l1, Node l2){
        // Converts the Objects to Strings
        String s1 = l1.val.toString();
        String s2 = l2.val.toString();
        LinkedList<Node> list = new LinkedList<Node>();

        // Adds the other elements from the list to create a String version of
        // the integers
        while (l1.next != null || l2.next != null){
            if (l1.next != null){
                l1 = l1.next;
                s1 += l1.val;
            }

            if (l2.next != null){
                l2 = l2.next;
                s2 += l2.val;
            }
        }

        // Parses the Strings to Longs then adds up the sum, which is then turned
        // into a char array
        char[] sum = String.valueOf(Long.parseLong(s1) + Long.parseLong(s2)).toCharArray();
        // Converts the chars to the number it represents and adds as a node to the list
        for (char c : sum){
            Node nd = new Node(Character.getNumericValue(c));
            list.add(nd);
        }
        initList(list);
        return list.get(0);

    }

    public static void printList(Node n){
        while (n != null){
            System.out.print(n.val + " ");
            n = n.next;
        }
        System.out.println(" ");

    }

    // Makes list a singly-linked list by linking the next nodes
    public static void initList(LinkedList<Node> l){
        for (int i = 0; i < l.size()-1; i++){
            l.get(i).next = l.get(i+1);
        }
    }


    public static void main(String[] args){
        LinkedList<Node> test1 = new LinkedList<Node>();
        LinkedList<Node> test2 = new LinkedList<Node>();
        LinkedList<Node> test3 = new LinkedList<Node>();

        /**Test 1: Adding the lists**/
        Random rand = new Random();

        int upper1 = rand.nextInt(9) + 1;

        // Populating the test linked lists
        for (int i = 1; i < upper1; i++){
            int upper2 = rand.nextInt(9) + 1;
            Node nd = new Node(upper2);
            test1.add(nd);
        }

        for (int i = 1; i < upper1; i++){
            int upper2 = rand.nextInt(9) + 1;
            Node nd = new Node(upper2);
            test2.add(nd);
        }

        initList(test1);
        initList(test2);

        System.out.print("Number 1: ");
        printList(test1.get(0));
        System.out.print("Plus number 2: ");
        printList(test2.get(0));
        System.out.print("Equals: ");

        Node head = addList(test1.get(0), test2.get(0));
        printList(head);

        /**Test 2: Reversing the list**/
        String t = "This is a test";
        char[] chars = t.toCharArray();
        for (char c : chars){
            Node tmp = new Node(c);
            test3.add(tmp);
        }
        initList(test3);

        Node head1 = reverseList(test3);
        printList(head1);



    }

}
