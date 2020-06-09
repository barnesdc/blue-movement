

public class TwumasiPennoh {

     public static void main (String args []){
        printAllPermutations("abc");
    }

    /*
    Prompt 1: Given a string, find the longest substring which is palindrome.
    For example, if the given string is "ababad", the output should be "ababa".

    Psuedocode:
         palindrome - a word, phrase, or sequence that reads the same forwards or backwards
         Given "ababad"
         - find all palindromes in string
            * find all the substrings in the string
                ** loop through each character in string and save index of character as start index
                ** loop through the rest of string and save index of character + 1 as endIndex
                ** get the substring
            * check to see if the substring is a palindrome
                ** check to see if substring length is even or odd
                    -> if even,
                        * divide string into two parts. if the first part is equal to the second part = palindrome
                    -> if odd
                        * divide string into two parts excluding middle character. if first part is equal to
                        the reverse of the second part = palindrome
                ** once you know substring is palindrome, check if length is greater than max variable
                    -> if it is, save length as new max
                    -> save palindrome in longestPalindrome variable
         - find the longest palindrome out of all palindromes
                ** return longestPalindrome variable
     */
    public static String longestPalindromeSubstring(String input){
        int maxLength = 0;
        String longestPalindrome = "";
        for(int i = 0; i < input.length(); i++){
            int startIndex = i;
            for(int j = i; j < input.length(); j++){
                int endIndex = j+1;
                String substring = input.substring(startIndex, endIndex);
                boolean palindromeFound = isPalindrome(substring);
                if(palindromeFound){
                    if(substring.length() > maxLength) {
                        maxLength = substring.length();
                        longestPalindrome = substring;
                    }
                }
            }
        }

        return longestPalindrome;
    }

    /*
    Helper method for longestPalindromeSubstring
     */
    public static boolean isPalindrome(String substringInput){
        int length = substringInput.length();
        boolean palindromeFound = false;
        String firstPart = "";
        String secondPart = "";

        if(length > 0 && length % 2 == 0) {//length is even
            firstPart = substringInput.substring(0, length / 2);
            secondPart = substringInput.substring(length / 2, length);
        } else if (length > 0 && length % 2 != 0){//length is odd
            firstPart = substringInput.substring(0, length / 2);
            secondPart = substringInput.substring((length/2)+1, length);
        }

        String reversedSecond = "";
        for(int i = secondPart.length()-1; i >= 0; i--){
            reversedSecond = reversedSecond + secondPart.charAt(i);
        }
        if(firstPart.equals(reversedSecond)){
            palindromeFound = true;
        }
        else{
            palindromeFound = false;
        }
        return palindromeFound;
    }



    /*
    Prompt 2: Given a string str, the task is to print all the permutations of str. A permutation is an arrangement of all or part
    of a set of objects, with regard to the order of the arrangement. For example, if given "abb", the output should be
    "abb abb bab bba bab bba"
    */
    public static void printAllPermutations(String input){
       recursivePrintPermutations("", input);
    }


    //Recursive helper method for printAllPermutations
    public static void recursivePrintPermutations(String perm, String input){
        String restOfString = "";
        if (input.length() > 0) {
            for (int i = 0; i < input.length(); i++) {
                if (i == 0) { //rest of string is everything after first letter
                    restOfString = input.substring(i + 1); 
                } else { //rest of string is everything around letter
                    restOfString = input.substring(0, i) + input.substring(i + 1);
                }
                recursivePrintPermutations(perm + input.charAt(i), restOfString);
            }
        }
        else{
      	    System.out.print(perm + " " );
        }
    }
}