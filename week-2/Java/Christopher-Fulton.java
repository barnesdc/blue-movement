

import java.util.Scanner;



class Week2{

     static void permutation(String perm,String str) {
        if (str.length() == 0) { // if str is empty perm must be full permuation
            System.out.println(perm + " ");
            return;
        } 
        for (int i = 0; i < str.length(); i++) { 
            permutation(perm+str.charAt(i), str.substring(0, i)+str.substring(i+1, str.length()));// Loop through string recursively each time add current index to substring of rest of word. 
        } 
        
    } 


    
//     public static String  maxPalindrone(String str) {
//         str = str.replaceAll("\\s",""); // replace all spaces and turn upper to lower case for simplicity
//         str = str.toLowerCase();
//         StringBuilder tempStr = new StringBuilder();
//         StringBuilder tempBuilder = new StringBuilder();
//         String maxSubstring ="";
//         for(int i = 0;i<str.length();i++){
//             for (int j = i+1; j<=str.length(); j++){
//                 tempStr.append(str.substring(i,j)); // find all substrings of str 
//                 tempBuilder.append(tempStr.toString());// temp variable to hold object 
//                 if(tempStr.toString().equals(tempBuilder.reverse().toString()) && tempBuilder.length() > maxSubstring.length()){
//                     maxSubstring = tempStr.toString();// Check wheter or not substring is a palindrone and ifso if it's largest.
//                 }
//                 tempStr.setLength(0);// Reset string objects 
//                 tempBuilder.setLength(0);
//             }
//         }

// return maxSubstring;
//     }
    public static void main(String[] args) {
         //////////////////////Interface/////////////////////////////////////////////////////
        Scanner in = new Scanner(System.in);

        String  a = "a";
        String b = "b";
        System.out.println(b.compareTo(a));

        


















        // String str = "ABC";
        // for (int i = str.length()-1;i>0;i--){
        //     for (int j = i -1; j<str.length()-1; j++){
        //         System.out.println(str.substring(j, i));
        //     }
        // }

    //     System.out.println("To check for Palindron enter: 1");
    //     System.out.println("To print all permutations 2");
    //     String choice = in.nextLine();
    //     if (choice.equals("1")) {
    //         System.out.println("Enter string");
    //         String str = in.nextLine();
    //         System.out.println( "Largest palidrone: ");
    //         System.out.println(maxPalindrone(str));
    //     } else if (choice.equals("2")) {
    //         System.out.println("Enter String ");
    //         String str = in.nextLine();
    //         System.out.println("All permutations of " + str + ":"  );
    //         permutation("",str);
            
    //     }
    //     else {
    //         System.out.println("Incorrect choice");
    //     }
    // in.close();
     }
}