/*

Resouses
https://www.youtube.com/watch?v=V-sEwsca1ak
https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

*/

public class Palindrome

{

    public static String Palindrome1(String s) {
//we inizialized a max variable to track which is the longest palindrome
        int max = 0;
//we loop through the string. I inizialized center=1 to start looking for the palinfrom from both sides left and right
        for (int center = 1 ; center<s.length(); center++){
            // l is left
            int l = center - 1;
            //r is right
            int r = center +1;

            while (l >=0 && r <s.length){
                //continue expanding from both left and right sizes
            }


        }

        //This should return a substring that has the longest palindrome found
return max;


    }


}






/*

Resourses
https://www.youtube.com/watch?v=GCm7m5671Ps

https://drive.google.com/file/d/1LwvCYLx6FU2egVvUGRb3VGRtyZsmNZNZ/view



*/




//this function will have three parameters: the fist one is a str, int left, int right


public static String Perm(String a, int l, int r){

    //if both sides are the same print the string because there is not other conmbination to create
    //This is your base case, otherwise the recursive function will never end

    if (l == r)
        System.out.println(a);
}
else{
// loop through the str setting l as the begining


for (int i =l ; i<=r; i++){
//we swap int l with int i
//it is also neded to incude a function that does the swap
    swap(a, l, i)
    //In this case a recursive call is a good way to solve this prompt
    // The problem will be solved by using a factorial methodology. We add l+1 to move forward.
    Perm(a, l+1, r);

    //at one point all the convinations will be done, so with this swap the code will backtrack

    swap(a, l, r)
}
}
