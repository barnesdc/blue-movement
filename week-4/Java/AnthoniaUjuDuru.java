
import java.util.*;

/**
 * A program that performs linkedlist functions.
 */
public class AnthoniaUjuDuru {
    /** 
     * 
     * @param list: the list to be converted to a string.
     * @return integer version of list.
     */
    public static int convertFromList(LinkedList<Integer> list) {
        // StringBuilder Object to store String representation of number
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < list.size(); i++){
            sb.append(list.get(i));
        }

        return Integer.parseInt(sb.toString());
    }

    /**
     * 
     * @param sum: the integer sum of both lists
     * @return the LinkedList sum of both lists
     */
    public static LinkedList<Integer> convertToList(int sum) {
        LinkedList<Integer> sumList = new LinkedList<Integer>();
        
        String listString = Integer.toString(sum);

        // loop through listString and append to linkedlist 
        for (int i = 0; i < listString.length(); i++) {
            char current = listString.charAt(i);
            sumList.add(Integer.parseInt(String.valueOf(current)));
        }
        return sumList;
    }

    /**
     * 
     * @param list to be reversed
     * @return reversed list
     */
    public static LinkedList<Character> reverseList(LinkedList<Character> list) {
        // convert to array to loop from the back 
        Character[] listArray = list.toArray(new Character[list.size()]);

        // create LinkedList to reverse
        LinkedList<Character> reverseList = new LinkedList<Character>();

        for (int i = listArray.length - 1; i >= 0; i--) {
            reverseList.add(listArray[i]);
        }
        
        return reverseList;
    }

    /**
     * The main function
     * @param args Not used.
     */
    public static void main(String[] args) {
        // Problem 1
        // Create both linkedlists
        LinkedList<Integer> linkOne = new LinkedList<Integer>();
        LinkedList<Integer> linkTwo = new LinkedList<Integer>();

        // add numbers
        linkOne.add(2);
        linkOne.add(5);
        linkOne.add(7);

        int intOne = convertFromList(linkOne);

        linkTwo.add(9);
        linkTwo.add(9);
        linkTwo.add(9);

        int intTwo = convertFromList(linkTwo);

        int sum = intOne + intTwo;

        System.out.println(sum);

        // Problem 2
        // create linkedlists for second problem
        LinkedList<Character> link1 = new LinkedList<Character>();

        link1.add('I');
        link1.add(' ');
        link1.add('l');
        link1.add('o');
        link1.add('v');
        link1.add('e');
        link1.add(' ');
        link1.add('G');
        link1.add('e');
        link1.add('e');
        link1.add('k');
        link1.add('s');
        link1.add(' ');
        link1.add('f');
        link1.add('o');
        link1.add('r');
        link1.add(' ');
        link1.add('G');
        link1.add('e');
        link1.add('e');
        link1.add('k');
        link1.add('s');

        LinkedList<Character> linkReverse = reverseList(link1);

        System.out.println(linkReverse);
    }


}