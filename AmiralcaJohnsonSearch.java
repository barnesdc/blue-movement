import java.util.*;

class AmiralcaJohnsonSearch{
    public static void main(String args[]){
        // Prompt 1: Stone's Love
        // Example input
        // Line 1:
        int numDays = 5; // number of days (n) 
        int q = 4; //  number of queries (q)
        // Line 2: 
        int numStones[] = {1, 2, 3, 4, 5}; // number of stones collected each day 
        // Line 3: 
        int m[] = {3, 8, 10, 14}; //number of stones collected (m)
        // Output: number of days taken to collect m number of stones

        // Prompt 2: Repeated K Times
        // Example input
        // Line 1:
        int n = 5; // size of array
        // Line 2:
        int arr[] = {2, 2, 1, 3, 1}; // array of integers
        // Line 3:
        int k = 2; // number of occurences
        // Output: smallest number in the array that has occurred k number of times
        // Print statement
        System.out.println(smallestOccurence(arr, n, k));
    }
    // Prompt 1: Stone's Love
    // Function to find the number of days taken to collect stones
    public static int collectStones(numDays, q, m){
        
    }
    // Prompt 2: Repeated K Times
    // Function to find the smallest number in the array that occurs k times
    public static int smallestOccurence(int arr[], int n, int k){
        int minNum = 0;
        int count = 0;
        // Sort the array of integers
        Arrays.sort(arr);
        // Outer loop: loops through each element in the array of integers from left to right
        for(int i = 0; i < n; i++){
            // If element in the array is > 0, count = 1 for 1 occurence
            if (arr[i] > 0){
                count = 1;
            }
                // Inner loop: loops to the right of the current element to check if there is another occurrence of the same element
                for(int j = i + 1; j < n; j++){
                    // If there is another occurrence on the right side, increase count by 1
                    if (arr[i] == arr[j]){
                        count = count + 1;
                    } 
                    // If count = k, output smallest number in the array
                    if (count == k){
                        minNum = Math.min(minNum, arr[i]);
                    }
            }
        }
        return minNum;
        }
    }