package week8;
import java.util.*;
import java.lang.*;

public class Week8 {
	
	public static void main(String [] args) {
//		int listSize = 20;
//		int [] array = {1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4};
//		int kTimes = 8;
//		System.out.println(repeatedKTimes(listSize, array, kTimes));
		
		
		
		//CASES FOR PROMPT 1
		/*
		 * first case
		 */
//		int [] daysAndQueries = {5, 4};
//		int [] numPerDay = {1, 2, 3, 4, 5};
//		int [] stonesCollected = {3, 8, 10, 14};
//		stonesLove(daysAndQueries, numPerDay, stonesCollected);
		
		
		/*
		 * second case
		 */
//		int [] daysAndQueries = {20, 16};
//		int [] numPerDay = {40, 31, 39, 7, 27, 10, 15, 22, 2, 25, 41, 44, 29, 32, 45, 10, 38, 36, 6, 1};
//		int [] stonesCollected = {20, 418, 439, 251, 363, 331, 101, 328, 49, 460, 244, 390, 142, 384, 47, 470, 295, 263, 343, 97};
//		stonesLove(daysAndQueries, numPerDay, stonesCollected);

	}
	
	
	/*
	 * Promp1: Stone's Love
	 * You are given the number of stones, she collects each day for N numbers of days, 
	 * starting from the very first day. Now you are given Q queries, in each query her 
	 * friend shambhavi asks you the number of days she has taken to collect M number of 
	 * stones. Please note that each query contains the different number of M.
	 * 
	 * Input: 
	 * First line contains N and Q, the number of days and number of queries. Second line 
	 * contains N integers, in which ith integer denotes the number of stones she has 
	 * collected on ith day. Then next line contains Q space-separated integers, M, where 
	 * ith M denotes the ith query, i.e., number of stones.
	 * 
	 * Output:
	 * For each of the Q queries, you have to output the number of days she has taken to 
	 * collect M number of stones in a new line.
	 */
	
	public static int numDaysToCollectStones(int[] numPerDays, int[] orig, int numStones){
        int maxIndex = numPerDays.length-1;
        int minIndex = 0;
        int returnNum = -1;
        while(maxIndex >= minIndex){
            int middleIndex = (maxIndex + minIndex)/2;
            boolean firstPassCase = numPerDays[middleIndex] == numStones;
            boolean secondPassCaseA = (numPerDays[middleIndex] - numStones) >= 0; 
            boolean secondPassCaseB = middleIndex != 0 && numPerDays[middleIndex-1] != numStones && (numPerDays[middleIndex-1]+orig[middleIndex] >= numStones);
            if(secondPassCaseA){
            	if(numPerDays[middleIndex] == numStones) {
            		returnNum = middleIndex+1;
            		break;
            	}else {
            		returnNum = middleIndex+1;
            		maxIndex = middleIndex-1;
            	}
            }
            else if(numPerDays[middleIndex] > numStones){
                maxIndex = middleIndex-1;
            }
            else if(numPerDays[middleIndex] < numStones){
                minIndex = middleIndex+1;
            }
        }
        return returnNum;
    }
	
	public static void stonesLove(int[] daysAndQueries, int[] numPerDay, int[] stonesCollected) {
		int[] orig = new int[numPerDay.length];
        for(int i = 0; i < numPerDay.length; i++){
            orig[i] = numPerDay[i];
            if(i != 0){
                numPerDay[i] = numPerDay[i-1] + numPerDay[i];
            }
        }
        
        for(int i = 0; i < daysAndQueries[1]; i++){
            System.out.println(numDaysToCollectStones(numPerDay, orig, stonesCollected[i]));
        }
	}
	
	
	
	/*
	 * Prompt 2: Repeated K Times
	 * Given a List of N number a1,a2,a3........an, You have to find smallest number from the
	 * List that is repeated in the List exactly K number of times.
	 */
	public static int repeatedKTimes(int listSize, int[] integerArray, int kTimes) {
		Arrays.sort(integerArray);
        int currentInt = 0;
        int currentIntCount = 0;
        for(int i = 0; i < integerArray.length; i++){
            if(currentInt != integerArray[i] && currentIntCount == kTimes){
                break;
            }
            else if(currentInt != integerArray[i] && currentIntCount != kTimes){
                currentInt = integerArray[i];
                currentIntCount = 1;
            } 
            else{
                currentIntCount++;
            }
        }

        return currentInt;
	}
}
