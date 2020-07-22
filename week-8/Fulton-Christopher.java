/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes

*/
import java.util.*;
import java.lang.Integer;

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
        int total = 0;
        for(int i = 0; i < line3.length; i++){
            for(int j = 0; j < line2.length;j++){
                total+= Integer.parseInt(line2[j]);
                if(total >= Integer.parseInt(line3[i])){
                    System.out.println(j+1);
                    total = 0;
                    break;
                }
            }
        }


    }
}
