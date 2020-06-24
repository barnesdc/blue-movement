
import java.util.Arrays;

public class cordero {

    public static boolean isPalindrome(String test){
        String test2;
        StringBuilder temp = new StringBuilder();
        temp.append(test);
        temp = temp.reverse();
        test2 = temp.toString();

        if(test.compareTo(test2)==0)return true;
        else return false;
    }

    public static String [] palindromeLongest(String pal){

        String [] a = new String [pal.length()];
        
        for(int i = 0;i<a.length;i++){
            a[i] = " ";
        }

        String [] max = new String [pal.length()];
        //max[0] = " ";

        //String [] max = new String [100];
        
        for(int i = 0;i<max.length;i++){
            max[i] = " ";
        }
        int j = 0;
        int k = 0;

        /*for(int i = 0;i<pal.length();i++){

            if(isPalindrome(pal.substring(i,pal.length()-1))){
                a[k] = pal.substring(i, pal.length()-1);
                k++;
            }
            
        }*/

        for(int i = pal.length()-1;i>1;i--){

            if(isPalindrome(pal.substring(0,i))){
                a[k] = pal.substring(0,i);
                k++;
            }
            
        }

        for(int i = 0;i<a.length-1;i++){
            

            if(a[i].compareTo(a[i+1])>0){

                if(max[j].compareTo(a[i])>0){

                }
                else if (max[j].compareTo(a[i])<0){
                    max[j] = a[i];
                }
                else if (max[j].compareTo(a[i])==0){
                    max[j+1] = a[i];
                    j++;
                }

            }
            else if (a[i].compareTo(a[i+1])<0){

                if(max[j].compareTo(a[i+1])>0){

                }
                else if (max[j].compareTo(a[i+1])<0){
                    max[j] = a[i+1];
                }
                else if (max[j].compareTo(a[i+1])==0){
                    max[j+1] = a[i+1];
                    j++;
                }

            }
            else if(a[i].compareTo(a[i+1])==0){

                if(max[j].compareTo(a[i])>0){

                }
                else if (max[j].compareTo(a[i])<0){
                    max[j] = a[i];
                    max[j+1] = a[i+1];
                    j++;
                }
                else if (max[j].compareTo(a[i])==0){
                    max[j+1] = a[i];
                    //max[j+2] = a[i+1];
                    j++;
                    j++;
                }
            }
        }

        return max;
    }

    public static void permutations(String input, String out){
        if (input.length() ==0){
            System.out.print(out +" ");
            return;
        }
        // loop checks and displays each possible three
        //(depends on length of input string in the test case it is three)
        // letter combination for permutations
        for(int i = 0;i<input.length();i++){

            //ith character of input
            char c = input.charAt(i);
            
            //the rest of the string after removing the ith character
            String remain  = input.substring(0,i) + input.substring(i+1);

            //recurssive call shifts to the next letter combination to check and display permutations
            //recurssiva call is exited when the input string is empty
            permutations(remain,out+c);

        }
    }

    public static void main (String [] args){
        
        String test = "abababad";
        String [] out = new String [100];
        out = palindromeLongest(test);
        int i = 0;
        while(out[i]!=" "){
        System.out.println(out[i]);
            i++;
        }

        String input  = "abb";
        permutations(input,"");
    }
    
}