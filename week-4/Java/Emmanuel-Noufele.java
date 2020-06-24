package hackerrsnk;

public class AddTwoNumbersLinkedList {
	private static ListNode head;
	
	private static class ListNode {
		int data;
		ListNode next;
		ListNode(int val) {
			data = val;
			next = null;
		}
	}
	
	public void addToLinkedList (ListNode node) {
		if(head == null) {
			head = node;
		} else {
			ListNode temp = head;
			while(temp.next != null) {
				temp = temp.next;
			}
			temp.next = node;
		}
	}
	
	public void printLinkedList(ListNode node) {
		ListNode temp = node;
		while(temp != null) {
			System.out.format("%d ", temp.data);
			temp = temp.next;
		}
	}
	
	public static ListNode reverseLinkedList (ListNode node) {
		if(node == null || node.next == null) {
			return node;
		}
		ListNode temp1 = node;
		ListNode temp2 = null;
		ListNode temp3 = node.next;
		while(temp3 != null) {
			temp1.next = temp2;
			temp2 = temp1;
			temp1 = temp3;
			temp3 = temp3.next;
		}
		temp1.next = temp2;
		return temp1;
	}
	
	public static ListNode getSumOfTwoNumbers(ListNode l1, ListNode l2) {
		ListNode newList = null;
		ListNode temp = null;
		int sum = 0;
		int carry = 0;
		int getNewHead = 0;
		while (l1 != null || l2 != null) {
			getNewHead++;
			sum = carry;
			if(l1 != null) {
				sum += l1.data;
				l1 = l1.next;
			}
			
			if(l2 != null) {
				sum += l2.data;
				l2 = l2.next;
			}
			
			carry = sum / 10;
			sum = sum % 10;
			
			if (getNewHead == 1) {
				temp = new ListNode(sum);
				newList = temp;
			} else {
				ListNode newNode = new ListNode(sum);
				temp.next = newNode;
				temp = temp.next;
				
			}
			
			if(carry != 0) {
				ListNode newCarryNode = new ListNode(carry);
				temp.next = newCarryNode;
			}
			
		}
		return newList;
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		AddTwoNumbersLinkedList list = new AddTwoNumbersLinkedList();
		
		// Initialize the first list
		ListNode firstHead = new ListNode(5);
		list.addToLinkedList(firstHead);
		list.addToLinkedList(new ListNode(6));
		list.addToLinkedList(new ListNode(3));
		head = null;
		
		// Initialize the second list
		ListNode secondHead = new ListNode(8);
		list.addToLinkedList(secondHead);
		list.addToLinkedList(new ListNode(4));
		list.addToLinkedList(new ListNode(2));
		
		System.out.print("First Number: ");
		list.printLinkedList(firstHead);
		System.out.println();
		System.out.print("Second Number: ");
		list.printLinkedList(secondHead);
		
		// Reverse the first list
		ListNode newFirstList = reverseLinkedList(firstHead);
		
		// Reverse the second list
		ListNode newSecondList = reverseLinkedList(secondHead);
		
		// Calculate the sum of the two numbers
		ListNode result = getSumOfTwoNumbers(newFirstList, newSecondList);
		
		// Reverse the sum to get the final result
		ListNode finalResult = reverseLinkedList(result);
		System.out.println();
		System.out.print("Second Number: ");
		list.printLinkedList(finalResult);
		
	}

}

package hackerrsnk;


public class reverseSentence {	
	public static class ListNode {
		char data;
		ListNode next;
		ListNode(char val) {
			data = val;
			next = null;
		}
	}
	
	public void printLinkedList(ListNode node) {
		ListNode temp = node;
		while(temp != null) {
			System.out.format("%c", temp.data);
			temp = temp.next;
		}
	}
	
	public static ListNode getLinkedListFromString(String str) {
		ListNode result = null;
		ListNode temp = null;
		
		for(int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			ListNode node = new ListNode(c);
			if(result == null) {
				result = node;
				temp = result;
			} else {
				temp.next = node;
				temp = temp.next;
			}
		}
		return result;
	}
	
	public static ListNode reverseWords(ListNode node) {
		if (node == null) {
			return node;
		}
		// variable to track the start position of a word
		ListNode start = null;
		// variable to track the end of the sentence
		ListNode end = null;
		// variable to track starting position of the sentence
		ListNode temp = null;
		
		// Initialize start to the first character
		start = node;
		
		while (node != null && node.data != ' ') {
			// keep track of the previous node with previous character
			end = node;
			node = node.next;
		}
		
		// Case when the sentence is just one word
		if(node == null) {
			node = start;
			return node;
		}
		
		// flag to check when we are done
		boolean done = false;
		
		while (done == false) {
			
			//swap the space to the beginning of the word
			ListNode temp1 = node.next;
			node.next = start;
			start = node;
			node = temp1;
			
			ListNode prev = null;
			
			//set the beginning of the remaining sentence
			temp = node;
			
			// repeat the process until we get the next space
			while (node != null && node.data != ' ') {
				prev = node;
				node = node.next;
			}
			// make the new space point to the previous space
			prev.next = start;
			
			// the new space should point to the beginning of the sentence
			start = temp;
			if(node == null) {
				done = true;
			}
		}
		
		//set the head to the new sentence
		node = temp;
		
		// set the last node next to null
		end.next = null;
		return node;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		reverseSentence inst = new reverseSentence();
		
		String str = "I love Geeks for Geeks";
		
		ListNode list = getLinkedListFromString(str);
		
		System.out.print("Original string: ");
		inst.printLinkedList(list);
		
		ListNode result = reverseWords(list);
		
		System.out.println();
		System.out.print("Reverse string: ");
		inst.printLinkedList(result);
		
		
	}

}

