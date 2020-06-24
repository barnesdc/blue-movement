import java.util.LinkedList;
import java.util.Scanner;

public class AmiralcaJohnsonLinkedList {

    public static void main(String args[]){
        // Prompt 1: Sum of LinkedList 
        // Input Scanner to get input from user
        Scanner input = new Scanner(System.in);

        // Create intList LinkedList for input
        LinkedList<Integer> intList = new LinkedList<Integer>();
        // Prompt user to input 2 numbers
        System.out.println("Please enter 2 numbers to add: ");
        for(int i = 0; i < 2 ; i++){
            intList.add(input.nextInt());
        }
        // Print sum of inputted numbers
        System.out.println("The sum of the numbers is: " + sum(intList));  
        
        // Space between outputs
        System.out.println("");

        // Prompt 2: Reversed LinkedList
        // Create orginal LinkedList
        LinkedList<String> sentence = new LinkedList<String>(); 
        // Example input
        sentence.add("I");
        sentence.add("love");
        sentence.add("Geeks");
        sentence.add("for");
        sentence.add("Geeks");
        // Print LinkedList before reverse
        System.out.println("LinkedList Before Reverse: ");
        System.out.println(sentence);

        // Space between outputs
        System.out.println("");

        // Create new LinkedList
        LinkedList<String> newSentence = reverse(sentence);
        // Print LinkedList after reverse
        System.out.println("LinkedList After Reverse: ");
        System.out.println(newSentence);
    }  

    // Prompt 1: Sum of LinkedList 
    // Sum LinkedList Function
    public static int sum(LinkedList<Integer> list){
        int sum = 0;
        for(int i = 0; i < list.size(); i++){
            sum = sum + list.get(i);
        }
        return sum; 
    } 

    // Prompt 2: Reversed LinkedList
    // Reverse LinkedList Function
    public static LinkedList<String> reverse(LinkedList<String> sentence){
        // Create result LinkedList
        LinkedList<String> result = new LinkedList<String>();
        for (int i = sentence.size() - 1; i >= 0; i--) {
          result.add(sentence.get(i));
        }
        return result;
      }
}        