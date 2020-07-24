/**
 * Week two string manipulation practice
 * 
 * @author Firaol Woldemariam
 * @version 06.10.2020
 */

public class Firaol_Woldemariam {
    
    /**
     * Takes in an argument an runs the necessary method
     * @param args The input string
     */
    public static void main(String args[])
    {
        longestPalindrome(args[1]);
    }
    
    /**
     * Returns the longest palindrome in a string
     * 
     * @param input The string being checked
     * @return The longest palindrome in a string
     */
    public static String longestPalindrome(String input)
    {
        String palindrome = ""; 
        
        for(int i = 0; i < input.length(); i++)
        {
            for(int j = input.length() - 1; j == 0; j--)
            {
                if(input.charAt(i) == input.charAt(j))
                {
                    input = input.trim().replaceAll("[^a-zA-z0-9]", "").toLowerCase();
                    input = input.substring(j, i);
                    palindrome = input;
                    break;
                }
            }
        }
        
        return palindrome; 
    }
}