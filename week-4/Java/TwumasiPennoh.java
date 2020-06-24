import java.util.*;
import java.lang.IllegalArgumentException;

public class TwumasiPennoh {

	public static void main(String[] args) {
		//TESTING FOR calculateSumList
		LinkedList<Integer> l1 = new LinkedList<Integer>();
		LinkedList<Integer> l2 = new LinkedList<Integer>();
		
		l1.add(5);
		l1.add(6);
		l1.add(3);
		
		l2.add(8);
		l2.add(4);
		l2.add(2);
		
		LinkedList<Integer> sumList = calculateSumList(l1, l2);
		Iterator<Integer> sumListIterator = sumList.iterator();
		while(sumListIterator.hasNext()) {
			System.out.print(sumListIterator.next());
		}
		System.out.println();
		
		//TESTING FOR reverseSentence
		LinkedList<Character> l3 = new LinkedList<Character>();
		String sentence = "I love Geeks for Geeks";
		for(int i = 0; i < sentence.length(); i++) {
			l3.add(sentence.charAt(i));
		}
		System.out.println(sentence);
		LinkedList<Character> l4 = reverseSentence(l3);
        
		Iterator<Character> iterator = l4.iterator();
		while(iterator.hasNext()){
			System.out.print(iterator.next());
		}

	}
	
	
	/*
	 * Prompt 1: Given two numbers represented by two linked lists, write a 
	 * function that returns sum list. The sum list is linked list representation
	 * of addition of two input numbers.
	 * 
	 * Solution:
	 * - Get the size of both lists
	 * - Use the greater size as the cap for the loop iterations
	 * - Using the size, get the integer representation of both linked lists
	 * - After that, add both integer representations to get the sum
	 * - Get the size of the sum integer representation
	 * - Loop through the sum integer representation
	 * - Add each integer in sum integer into sum linked list
	 */
	public static LinkedList<Integer> calculateSumList(LinkedList<Integer> l1, LinkedList<Integer> l2) {	
		int integer1 = 0, integer2 = 0;
		
		int placeValue1 = (int)Math.pow(10, l1.size()-1); //highest place val of int1
		int placeValue2 = (int)Math.pow(10, l2.size()-1); //highest place val of int2
		
		Iterator<Integer> iterator1 = l1.iterator();
		Iterator<Integer> iterator2 = l2.iterator();
		
		//error checking
		if(iterator1.hasNext() && !iterator2.hasNext()) {
			return l1;
		}else if (!iterator1.hasNext()  && iterator2.hasNext()){
			return l2;
		}
		else if(!iterator1.hasNext() && !iterator2.hasNext()) {
			 throw new IllegalArgumentException("Error: Invalid inputs. Both inputs are null");
		}
		
		while(iterator1.hasNext() || iterator2.hasNext()) {
			if(iterator1.hasNext()) {
				integer1 += placeValue1 * iterator1.next();
				placeValue1 /= 10;
			}
			if(iterator2.hasNext()) {
				integer2 += placeValue2 * iterator2.next();
				placeValue2 /= 10;
			}
		}
		
		int sum = integer1 + integer2;
		int sumLength = String.valueOf(sum).length();
		int sumPlaceVal = (int)Math.pow(10, sumLength-1);
		LinkedList<Integer> sumList = new LinkedList<Integer>();
		for(int i = 0; i < sumLength; i++) {
			int digit = sum/sumPlaceVal;
			sumList.add(digit);
			sum -= digit * sumPlaceVal;
			sumPlaceVal /= 10;
		}
		
		return sumList;
	}
	
	/*
	 * Prompt 2: Given a Linked List which represents a sentence S such that each node 
	 * represents a letter, the task is to reverse the sentence without reversing 
	 * individual words.
	 */
	public static LinkedList<Character> reverseSentence(LinkedList<Character> l1){
 		String sentence = "";
 		Iterator<Character> iterator = l1.iterator();
 		String currentWord = "";
 		//put linked list characters together to make a string variable
 		
 		if(!iterator.hasNext()) {
			 throw new IllegalArgumentException("Error: Invalid input. Input is null");
		}
 		
 		while(iterator.hasNext()){
 			char letter = iterator.next();
 			if(letter == ' '){
 				sentence = currentWord + " " + sentence;
 				currentWord = "";
 			}
 			else{
 				currentWord = currentWord + letter;
 			}
 		}
 
 		sentence = currentWord + " " + sentence;
 		//add each character in the sentence you created to a linked list
 		LinkedList<Character> reversed = new LinkedList<Character>();
 		for(int i = 0; i < sentence.length(); i++){
 			reversed.add(sentence.charAt(i));
 		}
 
 		return reversed;
	}
}
