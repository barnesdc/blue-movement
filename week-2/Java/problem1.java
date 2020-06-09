package Week2Assignment;
import java.util.Scanner;
public class problem1 {

public static void printSubString(String string, int lower, int upper) { 
	        System.out.println(string.substring(lower, upper + 1)); 
	    } 
	  
	      
	    static int longestPalSubstr(String string) { 
	        int maxLength = 1; // 
	  
	        int start = 0; 
	        int length = string.length(); 
	  
	        int lower, upper; 
	  
	        
	        for (int i = 1; i < length; ++i)  
	        { 
	           
	            lower = i - 1; 
	            upper = i; 
	            while (lower >= 0 && upper < length 
	                    && string.charAt(lower) == string.charAt(upper)) { 
	                if (upper - lower + 1 > maxLength) { 
	                    start = lower; 
	                    maxLength = upper - lower + 1; 
	                } 
	                --lower; 
	                ++upper; 
	            } 
	  
	           
	            lower = i - 1; 
	            upper = i + 1; 
	            while (lower >= 0 && upper < length 
	                    && string.charAt(lower) == string.charAt(upper)) { 
	                if (upper - lower + 1 > maxLength) { 
	                    start = lower; 
	                    maxLength = upper - lower + 1; 
	                } 
	                --lower; 
	                ++upper; 
	            } 
	        } 
	  
	        System.out.print("Longest palindrome substring is: "); 
	        printSubString(string, start, start + maxLength - 1); 
	  
	        return maxLength; 
	    } 
	  
	  
	    public static void main(String[] args) { 
	    	
	    	Scanner keyboard = new Scanner(System.in);
	    	
	    	System.out.println("Enter string");
	    	String string = keyboard.nextLine();
	    	
	    	System.out.println("Length is: " +  
                    longestPalSubstr(string)); 
	  
	 
	}
}


