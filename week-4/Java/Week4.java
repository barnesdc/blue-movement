
import java.util.*;
public class Week4{

public static int[] addElements(int num1, int num2, int carry ){
    int[] sum = new int[2];
    sum[0] = (num1+num2+carry)%10;
    sum[1] = (num1+num2+carry)/10;
    System.out.println((num1+num2+carry)/10);
    return sum;
}

public static LinkedList<Integer> sumLinkedList(LinkedList<Integer> list1, LinkedList<Integer> list2) {
    LinkedList<Integer> newLinkedList = new LinkedList<Integer>();
    int[] tempList1 = new int[2];
    int carry = 0;

    for (int i = list1.size()-1; i > -1; i--){
        tempList1 = addElements(list1.get(i), list2.get(i),carry);
        carry = tempList1[1];
        newLinkedList.add(tempList1[0]);
    }
   newLinkedList.add(tempList1[1]);
    Iterator<Integer> reverseLinkIterator = newLinkedList.descendingIterator();
    LinkedList<Integer> finalLinkedList = new LinkedList<Integer>();
    while (reverseLinkIterator.hasNext()){
        finalLinkedList.add(reverseLinkIterator.next());
    }

    return finalLinkedList;

}

public static LinkedList<String> rLinkedList(LinkedList<String> sLinkedList){
    int tempIndex = 0;
    LinkedList<String> finalLinkedList = new LinkedList<String>();
    for (int i = sLinkedList.size()-1; i > -1; i--){
        System.out.println(sLinkedList.get(i));
        if (sLinkedList.get(i).equals(" ")){
            // System.out.println(sLinkedList);
            for (int j = 0;  j<i;j++){
                finalLinkedList.add(sLinkedList.get(j));
            }
            tempIndex = i;
        }
    }

    return finalLinkedList;
}

public static void main(String[] args) {
    LinkedList<Integer> L1 = new LinkedList<Integer>();
    LinkedList<Integer> L2 = new LinkedList<Integer>();
    L1.add(5);
    L1.add(6);
    L1.add(3);
    L2.add(8);
    L2.add(4);
    L2.add(2);
    // System.out.println(sumLinkedList(L1, L2));

    LinkedList<String> sLinkedList = new LinkedList<String>();
    String testString = "I Love Geeks For Geeks";
    for (int i =0; i <testString.length(); i++ )
    sLinkedList.add(String.valueOf(testString.charAt(i)));
    System.out.println(rLinkedList(sLinkedList));
        
    } 
}