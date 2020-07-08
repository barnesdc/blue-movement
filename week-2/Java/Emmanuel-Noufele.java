public class longestSubstringPalindrome {
	
	public static String findLongestSubstring(String str) {
		String palindrome = "";
		int maxLength = 1;
		int begin = 0;
		int low;
		int high;
		
		for(int i = 0; i < str.length(); i++) {	
			// even case
			low = i;
			high = i + 1;
			while(low >= 0 && high < str.length() && str.charAt(low) == str.charAt(high)) {
				if(high - low + 1 > maxLength) {
					begin = low;
					maxLength = high - low + 1;
				}
				low--;
				high++;
			}
			
			// odd case
			low = i;
			high = i + 2;
			while(low >= 0 && high < str.length() && str.charAt(low) == str.charAt(high)) {
				if(high - low + 1 > maxLength) {
					begin = low;
					maxLength = high - low + 1;
				}
				low--;
				high++;
			}
		}
		palindrome = str.substring(begin, begin + maxLength);
		return palindrome;
	}

	public static void main(String[] args) {
		String input = "nhgdpsjdnfbeeebbjsjsb";
		String result = "";
		if(input.isEmpty() || input.length() == 1) {
			System.out.println(input);
		} else {
			 result = findLongestSubstring(input);
			
		}
		System.out.println(result);	
	}
}


public class printAllStringPermutations {
	
	public static void findAllPermutations(String input, String result) {	
		if(input.length() == 0) {
			System.out.println(result + " ");
			return;
		} else {
			for(int i = 0; i < input.length(); i++) {
				char inputChar = input.charAt(i);
				String remaining = input.subSequence(0, i) + input.substring(i + 1);
				findAllPermutations(remaining, result + inputChar);
			}
		}
	}
	public static void main(String[] args) {	
		String input = "IBM";
		String result = "";
		findAllPermutations(input, result);
	}
}
