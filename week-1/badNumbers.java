import java.util.Arrays;
import java.lang.*;

public class badNumbers {
    /** 
    * This is the main method which makes use of findAvg method. 
    * @param args Unused. 
    * @return Nothing. 
    */
    public static void main(String[] args) {
        int[] array = {7, 18, 2, 30, 1, 10, 3, 15};
        int [] arr = {37,7,22,15,49,60};
        
        int lengthLongestSubset = findLongestSubset(array, 3, 26);

        System.out.println(lengthLongestSubset);
    }

    /** 
     * This method helps find the longest subset. 
     * @param array the array of numbers.
     * @param lowerBound the minimum range.
     * @param upperBound the max range.
     * @return the longest subset outside of the bad numbers.
     */
    public static int findLongestSubset(int[] array, int lowerBound, int upperBound) {
        // Sort the array for easier traversal
        Arrays.sort(array);

        // [1, 2, 3, 7, 10, 15, 18, 30] 
        int max = 0;
        int current = 0;
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] >= lowerBound && array[i] <= upperBound) {
                current = i+1;
                if (array[current] > upperBound) {
                    array[current] = upperBound;
                }
                int diff = array[current] - array[i];
                max = Math.max(diff, max);
            }
        }
        return max;
    }
}