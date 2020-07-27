/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes

*/

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
class Main {


    static int lowestIntLinearSearch(int[] values, int k){
        Map<Integer,Integer> elements = new HashMap<Integer,Integer>();
        int minInt = Integer.MAX_VALUE;
        for(int value: values){
            if(!elements.containsKey(value))
                elements.put(value,1);
            else {
                elements.put(value, elements.get(value) + 1);
                if(value < minInt && elements.get(value) == k )
                    minInt = value;
            }


        }
        return  minInt;
    }

    static int binarySearch(int[] totals, int value){
        if(totals[0] >= value)
            return 1;
        int start = 0;
        int end = totals.length-1;
        while(start <= end){
            int middle = start + (end - start)/ 2;
            if(totals[start] >= value)
                return start + 1;

            if(totals[middle] < value)
                start = middle + 1;
            else if(totals[middle] > value)
                end = middle - 1;
        }

        return end;
    }
    public static void  main(String[] args)  {
        int[] N = {1,2,3,4,5};
        int[] totals = new int[5];
        int[] queries = {3,8,10,14};
        int total = 0;
        for(int i = 0; i < totals.length; i++){
            total+= N[i];
            totals[i] = total;
        }
        for (int query : queries) System.out.println(binarySearch(totals, query));
        int[] N2 = {2,2,1,3,1};
        System.out.println(lowestIntLinearSearch(N2, 2));
    }


}