#include <iostream>
#include <string>
using  namespace std;
//------------------------------longest substring palindrome.---------------------------
/*
 * - Given a string, find the longest substring which is palindrome.
 * For example, if the given string is "ababad", the output should be "ababa".
 *
*/

//function which find the longest substring which is palindrome
//return Type: string
string longSubPol(string str){
    // firs convert string to lower case
    for_each(str.begin(), str.end(), [](char & c) {
        c = ::tolower(c);
    });

    //get the length of the string
    int length = str.length();

    //check if the string is null
    //return the charater of empty string
    if(str == "" || length < 2){
        return str;
    }

    //initiate the lowIndex and right indexes
    int lowIndex, right, start = -1, size =0;
    for(int i=0; i < length*2-1; i++){
        lowIndex = i / 2;
        right = i/2 + i%2;
        while(lowIndex >= 0 && right < length && str[lowIndex] == str[right]){
            if(size < (right - lowIndex + 1)){
                size = (right - lowIndex + 1);
                start = lowIndex;
            }
            lowIndex--;
            right++;
        }
    }
    return str.substr(start, size);
}

//-----------------------------------------------END-------------------------------------------

//---------------------------------------permutation--------------------------------------------
/*
 * Given a string str, the task is to print all the permutations of str.
 * A permutation is an arrangement of all or part of a set of objects,
 * with regard to the order of the arrangement. For example, if given "abb",
 * the output should be "abb abb bab bba bab bba"
 * */

//Function to print all the permutation of str
//return Type : void
void permutation(string str, string ans){

    //get the length of the string
    int length = str.length();

    //string storing the result
    //string ans;

    //if string empthy, return empthy string
    if( str.length() == 0){
        cout << ans + " " ;
        return;
    }

    for(int i=0; i< length; i++){
        // ith character of str
        char ch = str[i];

        //Rest of the string after
        //the ith character
        string ros = str.substr(0, i) + str.substr(i+1);

        // Recurvise call
        permutation(ros, ans + ch);
    }
}

//---------------------------------------END--------------------------------------------------

void TEST1(){
    cout << "TEST FOR LONGEST SUBSTRING POLINDROME "<<endl;
    string s1, s2, s3, s4;
    s1= "ababad";
    cout<< "s1= "<< longSubPol(s1)<<endl;


    s2 ="cbbdhhhhhhhhdsdsbdJDABFBGhciagiKHFOBAF";
    cout<<"s2= "<<longSubPol(s2)<<endl;


    s3="aIbohPhoBdhgsgabsodaggdnabgdabfoiA";
    cout<<"s3= "<<longSubPol(s3)<<endl;


    s4="ababababaabbabababbababaaababababaabababbababaabbab";
    cout<<"s4= "<<longSubPol(s4)<<endl;
    cout <<endl;

}

void TEST2(){
    cout << "TEST FOR PERMUTATION "<<endl;
    string p1,p2,p3,p4;
    p1= "abb";
    cout << "p1= ";
    permutation(p1, "");
    cout <<endl;


    p2= "NimaD";
    cout << "p2= ";
    permutation(p2, "");
    cout <<endl;


    p3= "abab";
    cout << "p3= ";
    permutation(p3, "");
    cout <<endl;


    p4= "foiA";
    cout << "p4= ";
    permutation(p4, "");
    cout <<endl;
}
int main() {
    TEST1();
    TEST2();


    return 0;
}

