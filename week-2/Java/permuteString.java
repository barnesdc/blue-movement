import java.util.*;

public class permuteString {
    public static void main(String[] args) {
        String str = "abb";
        permuteStringPrint(str, "");
    }

    public static void permuteStringPrint(String str, String permute) {
        // dynamic programming approach/recursion

        // base case: if str is empty 
        if (str.length() == 0) {
            System.out.println(permute);
            return;
        } 

        // if string isn't empty 
        for (int i = 0; i < str.length(); i++) {
            // current char that will be at the front of the permute string 
            // first time == a
            // second time == b1
            // third time == b2
            char currentChar = str.charAt(i);
            
            // the substring that must now be permuted 
            // first time == b1b2
            // second time == b2
            // third time == ""
            String rest = str.substring(0, i) + str.substring(i+1);
            
            // recursive call
            // first time == (b1b2, a)
            // second time == (b2, b1)
            // third time == ("", b2)
            permuteStringPrint(rest, permute + currentChar);

            // after third time recurse back up and now permute string == ab1b2
            // now increment current char which will now be b1 and repeat above processes
        }
    }
    
}