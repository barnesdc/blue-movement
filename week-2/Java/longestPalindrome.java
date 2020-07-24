
import java.util.*;

public class longestPalindrome {
    public static void main(String[] args) {
        String palindrome = "ababad";
        String longest = longestSub(palindrome);
        System.out.println(longest);
    }

    public static String longestSub(String pal) {
        // base case 
        if (pal == null) {
            return "Error: Invalid String";
        }
        if (pal.length() == 0 || pal.length() == 1) {
            return pal;
        }
        // want to go dynamic programming approach
        // loop through "center points"
        // extend left and right for as long as the substring 
        int maxLength = 1;

        int start = 0; // starting index for the substring; update when find longer substring
        
        // pointers for the beginning and ending index of substring
        int left = 0;
        int right = 0;

        // loop through and consider every character as center 
        for (int i = 1; i < pal.length(); i++) {
            // when substring length is even
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < pal.length() 
            && pal.charAt(left) == pal.charAt(right)) {
                if (right - left + 1 > maxLength) {
                    start = left; 
                    maxLength = right - left + 1;
                }
                --left; // extend left
                ++right; // extend right
            }

            // when substring length is odd
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < pal.length()
            && pal.charAt(left) == pal.charAt(right)) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1; 
                }
                --left; // extend left 
                ++right; // extend right
            }
        }
        
        // rebuild the string using start index and maxLength
        StringBuilder sb = new StringBuilder();
        for (int i = start; i < start + maxLength; i++) {
            sb.append(pal.charAt(i));
        }
        return sb.toString();
    }
}