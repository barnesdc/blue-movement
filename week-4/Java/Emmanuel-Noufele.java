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
