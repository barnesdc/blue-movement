import java.util.*;
import java.io.*;

/*Given a string, find the longest substring which is palindrome. For example, if the given string is "ababad", the output should be "ababa".
* Given a string str, the task is to print all the permutations of str. A permutation is an arrangement of all or part of a set of objects,
* with regard to the order of the arrangement. For example, if given "abb", the output should be "abb abb bab bba bab bba" */

public class Amaya_Howard_Carswell{

    //Helper function
    public static boolean checkPalindrome(String str){
        int length = str.length();
        int i = 0;
        int j = length - 1;
        //This is just to prevent calling the charAt method repeatedly
        char[] strChars = str.toCharArray();
        while (i < length/2){
            if (strChars[i] != strChars[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    public static String longestPalindrome(String str) {
        String longest = "";
        int longestLength = -1;
        int strLength = str.length();
        //This will keep track of the parts of the sentence that have already
        //been decided as palindromes (or not)
        //First index is starting index, second is the last index of substring
        int palins[][] = new int[strLength][strLength];

        if (strLength == 0)
            return null;

        for (int i = 0; i < strLength; i++){
            //A 1-letter substring is automatically a palindrome
            palins[i][i] = 1;
            for (int j = strLength-1; j > i; j--){
                //If a substring is a palindrome then the substring within it
                //is also a palindrome
                if (palins[i][j] == 1){
                    palins[i+1][j-1] = 1;
                    continue;
                }

                if (checkPalindrome(str.substring(i, j + 1))){
                    palins[i][j] = 1;
                    //Checks if current palindrome is the longest
                    if ((j - i + 1) > longestLength){
                        longestLength = j - i + 1;
                        longest = str.substring(i, j + 1);
                    }
                }
                else
                    palins[i][j] = 0;
            }
        }

        return longest;
    }


    //Used for a recursive function so initialized outside of function so values
    //aren't reset
    public static ArrayList<String> permutations = new ArrayList<>();

    public static int fact(int n){
        if (n == 0)
            return 1;
        return n*fact(n-1);
    }

    //Swaps characters within a string
    public static String swap(String str, int a, int b){
        char[] strTemp = str.toCharArray();
        char temp = strTemp[a];
        strTemp[a] = strTemp[b];
        strTemp[b] = temp;

        String ret = new String(strTemp);
        return ret;
    }

    public static ArrayList<String> getPermutations(String str, int start, int end) {

        //Checks if program has reached the end of the sentence
        //Which means that one round of permutations is done
        if (start == end){
            permutations.add(str);
        }

        else{
            for (int i = 0; i < end; i++){
                //System.out.println(start);
                str = swap(str, start, i);
                //System.out.println("First str "+ str);

                //Now computes the permutations with a different start to swap
                //as it continues on through the string
                getPermutations(str, start + 1, end);
                //Resets the swap so that it doesn't mess with the order
                str = swap(str, start, i);

            }
        }
        return permutations;
    }
    public static void main(String[] args) {
        //System.out.println("Hello World!");

        //Result should be "fgheghf"
        String palinResult = longestPalindrome("ccbbabbdddfghehgf");
        System.out.println(palinResult);

        //Result should be 24 different permutations
        //However I kept getting solutions that were a little more or less
        String permuteTester = "abcd";
        ArrayList<String> perms = getPermutations(permuteTester, 0, permuteTester.length()-1);
        System.out.println(perms);
        System.out.println(perms.size());
    }
}
