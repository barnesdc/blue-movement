
/**Given a string, find the longest substring 
which is palindrome. For example, if the given string is "ababad", the output should be "ababa".
**/

  /**Given a string str, the task is to print all the permutations of str. A permutation is an 
arrangement of all or part of a set of objects, with regard to the order
 of the arrangement. For example, if given "abb", the output should be "abb abb bab bba bab bba"
 **/


public class SabrinaNettersWk2Assignment{
    public static void main(String args[]){
        
        //method for displaying longest palindrome
        String substring = "ababad";
        longestPal(substring); 
       
       
        //method for showing permutations of a string
        String str = "abc";
        System.out.print("The permutations are: ");
        Permutations(str, " ");
        
    }
     
      static void Palindrome(String substring, int a, int b){ 
        System.out.println(substring.substring(a, b + 1)); 
    } 

    //function for finding longest palindrome
    public static int longestPal(String substring){
        int longestLength = 0;//value(length) of palindrome
       
        int startingPoint = 0;//start of palindrome 
        int stringLength = substring.length(); //length of substring
        int a;//start character reader in string
        int b; //next character reader in string
        
        for (int i = 1; i < stringLength; i++)  
        { 
            // if palindrome has even length  
            // start at index 0 and index 1
            a = i - 1; 
            b = i; 
            while (a >= 0 && b < stringLength && substring.charAt(a) == substring.charAt(b)) { 
                if (b - a + 1 > longestLength) { 
                    startingPoint= a; 
                    longestLength = b - a + 1; 
                } 
                a--; 
                b++; 
            } 
  
            // if the palindrome has an odd length  
            //start at index 0 and index 2
            a = i - 1; 
            b = i + 1; 
            while (a >= 0 && b < stringLength && substring.charAt(a) == substring.charAt(b)) { 
                if (b - a + 1 > longestLength) { 
                    startingPoint = a; 
                    longestLength = b - a + 1; 
                } 
                a--; 
                b++; 
            } 
        } 
  
        if (longestLength>=2){
            System.out.print("Longest palindrome substring: "); 
            Palindrome(substring, startingPoint, startingPoint + longestLength - 1);
            }
            else 
              System.out.print("There is no palindrome");

        return longestLength; 
    }

  
    
    //function for finding permutations in string
     static void Permutations(String GivenStr, String str2){
        //if str is empty
        if (GivenStr.length() == 0) { 
            System.out.print(str2+" "); 
            return; 
        } 

        for(int i = 0; i < GivenStr.length(); i++){
            char ind = GivenStr.charAt(i);//getting specific character of string

            String perm = GivenStr.substring(0, i) + GivenStr.substring(i+1);//rest of string after character

            Permutations(perm, str2 + ind);//recursive method

        }
        
    }
    
}