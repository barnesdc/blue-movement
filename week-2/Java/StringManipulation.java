

public class StringManipulation {
    // helper function to test whether or not a given string is a palindrome
    static boolean isPalindrome(String s) {
        boolean isPal = false;
        
        if (s.length()<= 1) 
            isPal = true;
        // case sensitive, will not affect the original string
        s = s.toLowerCase();
        // only letters and digits
        for (int i = 0; i < s.length(); i++) {
            if (!Character.isLetter(s.charAt(i)) && !Character.isDigit(s.charAt(i)))
                s = s.replace(s.substring(i, i+1), "");
        }
        // compare each character to character on the opposite side of string until you reach halfway through the string or until you find two different characters
        for (int i = 0; i < s.length(); i++) {
            if (!(s.substring(i, i+1).equals(s.substring(s.length()-1-i, s.length()-i))))
                break;
            else if (i == s.length()/2)
                isPal = true;
            else 
                continue;
        }
        
        return (isPal);
    }
    // finds longest substring in String s that is a palindrome
    static String longestPalindrome(String s) {
        // starting from the length of the string and decreasing, go through each substring of length i and test if it is a palindrome
        for (int i = s.length(); i >=0; i--) {
            for (int j = 0; j <= s.length() - i; j++) {
                if (isPalindrome(s.substring(j, j+i))) {
                    return s.substring(j, j+i);
                }
            }
        }
        // sanity check, return empty string if all else fails
		return "";
    }
    // first attempt at Permutation String was to use a global String to store the prefix, before storing prefix as a second parameter.
    //String result = "";

    // function should print out all permuations of String s using recursion
    static void permutationString(String s, String prefix) {
        //for each character in s, recursively call function on the leftover substring with s being added to the prefix.
        if (s.length() >= 1) {
            for (int i = 0; i < s.length(); i ++) {
                permutationString(s.substring(0, i) + s.substring(i+1), prefix + s.substring(i, i+1));
            }
        } // base case: If s is one character, print that character with its prefic
        else {
            System.out.print(prefix + s + " ");
        }
    }
    public static void main(String[] args) {
        String result = longestPalindrome("abaBa");
        System.out.println(result);
        //In this case, the prefix is an empty string.
        permutationString("abb", "");
    }
}