
public class Blaine_Beltran {

    public static void main(String[] args) {
        printPalindromes("ababad");
        String permutation = "abb";
        allPermutations(permutation.toCharArray(), 0);
    }

    /**
     * PROMPT 1: Given a string, find the longest substring which is palindrome. For
     * example, if the given string is "ababad", the output should be "ababa"
     */

    public static boolean verifyPalindromes(String str) {
        for (int i = 0; i <= str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }

        return false;
    }// END verifyPalidromes method

    public static void printPalindromes(String str) {
        for (int i = 0; i <= str.length(); i++) {
            for (int j = i; j < str.length(); j++) {
                if (verifyPalindromes(str.substring(i, j + 1))) {
                    System.out.println(str.substring(i, j + 1));
                }
            }
        }
    }

    /**
     * PROMPT 2: Given a string str, the task is to print all the permutations of
     * str. A permutation is an arrangement of all or part of a set of objects, with
     * regard to the order of the arrangement. For example, if given "abb", the
     * output should be "abb abb bab bba bab bba"
     */

    private static void swap(char[] permut, int i, int j) {
        char temp = permut[i];
        permut[i] = permut[j];
        permut[j] = temp;
    }

    private static void allPermutations(char[] permut, int currentIndex) {
        if (currentIndex == permut.length - 1) {
            System.out.println(String.valueOf(permut));
        }

        for (int i = currentIndex; i < permut.length; i++) {
            swap(permut, currentIndex, i);
            allPermutations(permut, currentIndex + 1);
            swap(permut, currentIndex, i);
        }
    }

}