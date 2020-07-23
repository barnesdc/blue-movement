/**
Given two numbers represented by two linked lists, write a function that returns sum list.
 The sum list is linked list representation of addition of two input numbers.
**/

import java.util.*;
import java.io.*;

public class SabrinaNetters_Week4_LinkedList {

  public static void main(String[] args) {
    //method for finding sum of linked lists      
		LinkedList<Integer> num1 = new LinkedList<>();
    System.out.println("The sum of the lists is: "+SumOf(num1));

    //method for reversing linked list
    LinkedList<String> list = new LinkedList<String>();
    System.out.println("The reversed list: "+Reverse(list));
    

  }

//function for sum of linked lists
  public static LinkedList<Integer> SumOf (LinkedList<Integer> list){

      LinkedList<Integer> num1 = new LinkedList<>();
      // Input from user for list 1 
      System.out.println("Enter first input:");            
      Scanner scan1 = new Scanner(System.in);
      int list1 = scan1.nextInt();
      String FirstInput = Integer.toString(list1);
      LinkedList<Integer> Input1 = new LinkedList<>();
      for(int i = 0; i < FirstInput.length(); i++){
        Input1.add(((int)FirstInput.charAt(i)-48));
      }
  
      System.out.println("The first list is: "+Input1);
  
      //Input from user for list 2
      System.out.println("Enter second input:");
      Scanner scan2 = new Scanner(System.in);
      int list2 = scan2.nextInt();
      String SecondInput = Integer.toString(list2);
      LinkedList<Integer> Input2 = new LinkedList<>();
      for(int i = 0; i < SecondInput.length(); i++){
        Input2.add(((int)SecondInput.charAt(i)-48));
      } 
  
      System.out.println("The second list is: "+Input2);
  
      
      //sum of inputs
      int sum = list1 + list2;
      String sum1 = Integer.toString(sum); 
      
      //convert sum to LinkedList
      for(int i = 0 ; i<sum1.length() ; i++){
   
        num1.add(((int)sum1.charAt(i)-48));
      }
      return num1;
  }


      

//function for reversing linked list
  public static LinkedList<String> Reverse(LinkedList<String> sentence){
    LinkedList<String> S = new LinkedList<String>();
      S.add("I");
      S.add("love");
      S.add("Leeks");
      S.add("for");
      S.add("Geeks");
      System.out.println("\nThe original list: "+S);
    
      LinkedList<String> list = new LinkedList<>();
      for(int i = S.size()-1; i >= 0 ; i--){
        list.add(S.get(i));
      
        }     
        return list;
        
  }



}
