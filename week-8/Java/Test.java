import java.util.*;
class Test {    
    static int binarySearch(int[] arr, int key) {
            int low = 0;
            int high = arr.length - 1;
            while (low <= high) {
                int mid = (low + high)/2;
                if (arr[mid] < key) { // too low, 
                    low = mid+1;
                } else if (arr[mid] > key && arr[mid-1] > key) { // too high
                    high = mid - 1;
                } else {
                    return mid;
                }
            }
            return -1;
        }
        public static int daysToCollectStones(int[] days, int stones) {
            int[] totalStones = new int[days.length];
            totalStones[0] = days[0];
            for (int i = 1; i < days.length; i++) {
                totalStones[i] = totalStones[i-1] + days[i];
            }
            return binarySearch(totalStones, stones) + 1;
    }
    // Assumption that there will be at least one variable repeated K times
    public static int repeatedKTimes(int[] arr, int k) {
        Arrays.sort(arr);
        int timesRepeated = 1;
        int currentInt = arr[0];
        for (int i = 1; i < arr.length; i ++) {
            if (arr[i] != currentInt) {
                if (timesRepeated == k) {
                    return currentInt;
                } else {
                    currentInt = arr[i];
                    timesRepeated = 1;
                }
            } else {
                timesRepeated ++;
            }
        }
        return currentInt;
    }

     public static void main(String[] args) {
         int[] list = {1, 2, 3, 4, 5};
         System.out.println(daysToCollectStones(list, 10));
         int[] otherlist = {2, 2, 1, 3, 1};
         System.out.println(repeatedKTimes(otherlist, 2));
     }
}