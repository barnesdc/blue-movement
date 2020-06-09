

public class StringManipulation {

    static boolean isPalindrome(String s) {
        boolean isPal = false;
        
        if (s.length()<= 1) 
            isPal = true;
        
        s = s.toLowerCase();
        for (int i = 0; i < s.length(); i++) {
            if (!Character.isLetter(s.charAt(i)) && !Character.isDigit(s.charAt(i)))
                s = s.replace(s.substring(i, i+1), "");
        }
        
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

    static String longestPalindrome(String s) {
        for (int i = s.length(); i >=0; i--) {
            for (int j = 0; j <= s.length() - i; j++) {
                if (isPalindrome(s.substring(j, j+i))) {
                    return s.substring(j, j+i);
                }
            }
        }
		return "";
    }
    String result = "";
    static void permutationString(String s, String prefix) {
        if (s.length() >= 1) {
            for (int i = 0; i < s.length(); i ++) {
                permutationString(s.substring(0, i) + s.substring(i+1), prefix + s.substring(i, i+1));
            }
        } else {
            System.out.print(prefix + s + " ");
        }
    }
    public static void main(String[] args) {
        String result = longestPalindrome("ababa");
        System.out.println(result);
        permutationString("abb", "");
    }
}