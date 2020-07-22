/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes

*/
import java.util.*;
import java.lang.*;

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class TestClass {
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        */

        // Write your code here
        Scanner s = new Scanner(System.in);
        String[] line1 = s.nextLine().split(" ");
        String[] line2 = s.nextLine().split(" ");
        String[] line3 = s.nextLine().split(" ");
        int[] totals = new int[Integer.parseInt(line1[0])];
        int total = 0;
        for(int i = 0; i < totals.length; i++){
        total+= Integer.parseInt(line2[i]);
            totals[i] = total; 
    }
    
    for(int i = 0; i <Integer.parseInt(line1[1]); i ++){
        System.out.println(binarySearch(totals,Integer.parseInt(line3[i])));
    }
    
    
    


    }
    static int binarySearch(int[] totals, int value){
        if(totals[0] >= value)
            return 1;
        int start = 0;
        int end = totals.length-1;
        while(start <= end){
            int middle = (start + end) / 2;

            if(totals[middle] < value){
                start = middle + 1;
                if(totals[start] >= value)
                return start + 1;
            }

            else if(totals[middle] > value)
                end = middle - 1;
        }
        
        return 0;
    }
}
