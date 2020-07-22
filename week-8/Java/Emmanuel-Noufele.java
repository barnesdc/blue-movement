public class stoneLoves {
	public static int findDays(long[] stones, int query) {
		
		long []sum = new long [stones.length];
		sum[0] = stones[0];
		for(int i = 1; i < stones.length; ++i) {
			sum[i] = sum[i-1] + stones[i];
		}
		int left = 0;
		int right = sum.length - 1;
		while(left < right) {
			int mid = (left + right) /2;
			if(sum[mid] >= query) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return (left + 1);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long [] stones = {1,2,3,4,5};
		int query = 14;
		int days = findDays(stones, query);
		System.out.println("Senorita has taken " + days + " days to collect " + query + " stones!");

	}

}


import java.util.Map;
import java.util.TreeMap;

public class repeatedKTimes {
	public static int findNumber(int[] array, int k) {
		if(array.length == 0) {
			return 0;
		}
		Map<Integer, Integer> map = new TreeMap<>();
		for(int i: array) {
			map.put(array[i], map.getOrDefault(array[i], 0) + 1);
		}
		
		for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
			if(entry.getValue() == k) {
				return entry.getKey();
			}
		}
		return 0;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array = {5,5,5,8,8,8,1,1,1};
		
		int k = 3;
		int number = findNumber(array, k);
		System.out.println("The smallest number from the list that is repeated in the list exaclty " + k + " number of times is " + number);

	}

}
