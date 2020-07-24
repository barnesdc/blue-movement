import java.util.*;

public class AnthoniaUjuDuru {

	public static void main(String[] args) {
		/* 
			Stone's Love
		*/

        Scanner sc = new Scanner(System.in);
        int numDays = sc.nextInt();
        int numQueries = sc.nextInt();

        // collect the number of stones accumulated per day
        int[] totalSumStonesPerDay = new int[numDays];

        int totalSum = 0;

        for (int i = 0; i < numDays; i++) {
            totalSum += sc.nextInt();
            totalSumStonesPerDay[i] = totalSum;
        }

        // collect number of queries per day and output number of days to collect the stones
        for (int i = 0; i < numQueries; i++) {
            int numStones = sc.nextInt();
            int index = Arrays.binarySearch(totalSumStonesPerDay, numStones);
            if (index < 0) {
                index = Math.abs(index);
            } else {
                index++;
            }
            System.out.println(index);
        }

        /*
			Repeated k times 
        */

        // Write your code here

        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();  

        // collect all the integers 
        int[] arr = new int[length];
        for (int i = 0; i < length; i++) {
            arr[i] = sc.nextInt();
        }               

        int k = sc.nextInt();
        
        int count = 0;
        int current = 0;

        HashMap<Integer, Integer> myMap = new HashMap<>();

        for (int i = 0; i < length; i++) {
            if (myMap.get(arr[i]) == null) {
                myMap.put(arr[i], 1);
            } else {
                myMap.put(arr[i], myMap.get(arr[i]) + 1);
            }
        }

        int smallest = Integer.MAX_VALUE;

        for (int i = 0; i < length; i++) {
            if (arr[i] < smallest && myMap.get(arr[i]) == k) {
                smallest = arr[i];
            }
        }

        System.out.println(smallest);
	}
}