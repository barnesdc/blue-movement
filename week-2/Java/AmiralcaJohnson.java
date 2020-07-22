import java.util.*;

public class AmiralcaJohnson {

    public static void main(String args[]){
        // Example input
        String word = "dog";
        longestPalSubstr(word);
        printPerm(word, "");
        System.out.println("Longest Palindrome Substring: "); 
        printLongestPalSubstr(word, beginning, beginning + highestLen -1);
        System.out.println("Longest Palindrome Substring Length: " + highestLen);
    }
    // Print longest palindrome substring 
    static void printLongestPalSubstr(String word, int first, int last) {
        System.out.println(word.substring(first, last + 1));
    }
    // Find longest palindrome
    public static int longestPalSubstr(String word) {
        int highestLen = 0;
        int beginning = 0;
        int first;
        int last;

        // Get length of example word
        int wordlen = word.length();
        
        for (int i = 1; i < wordlen; i++) {
            // Palindrome with even length
            first = i - 1;
            last = i;
            while (first >= 0 && last < wordlen && word.charAt(first) == word.charAt(last)) {
                if (last - first + 1 > highestLen) {
                    beginning = first;
                    highestLen = last - first + 1;
                }
                first--;
                last++;
            }
            // Palindrome with odd length
            first = i - 1;
            last = i + 1;
            while (first >= 0 && last < wordlen && word.charAt(first) == word.charAt(last)) {
                if (last - first + 1 > highestLen) {
                    beginning = first;
                    highestLen = last - first + 1;
                }
                first--;
                last++;
            }
        }
        return highestLen;
    } 
    // Print permutations
    static void printPerm(String word, String result) {
        // # of permutations formula
        int perm = (wordlen - 1) * wordlen;

        for (int i = 0; i < word.length(); i++) {
            char a = word.charAt(i);
            String word1 = word.substring(0, i) + word.substring(i + 1);
            printPerm(word1, result + a);
        }
    }
}