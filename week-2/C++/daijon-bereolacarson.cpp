#include <iostream>
#include <string>

using namespace std;

// Given a string, find the longest substring which is palindrome. For example, if the given string is "ababad", the output should be "ababa".

/*
Questions:
    1. How can it tell a string is a palindrome?
    2. What are we passing into the function?
    3. How do we determine the longest palindrome substring in the string?
    4. What are we returning?

Assumptions:
    1. The program should run through each character in the string
    2. If the string can be read forwards and backwards, then store that substring in a new string variable
    3. Once the program is done, running through each character in the string, determine which string is longer.
    4. Whichever substring is longer is the character that will return.
*/

bool isPalindrome(string str){
    for(int i = 0; i <= str.size()/2; ++i){
        if(str[i] != str[str.size()-1-i]){
            return false;
        }
    }
    return true;
}

string longestSubstring(string str){
    //for loop that itirates through each character in the string
    //  for loop that itirates through the string backwards
    //  if both of these strings equal each other then it should be stored in a new array of strings

    int len = str.size();
    for(int size = len; size >= 1; --size){ // test every possible size
        for(int start = 0; start < len-size; ++start){
            if(isPalindrome(str.substr(start, size))){
                return str.substr(start, size);
            }
        }
    }

    return "";
}

// Given a string str, the task is to print all the permutations of str. A permutation is an arrangement of all or part of a set of objects, with regard to the order of the arrangement. For example, if given "abb", the output should be "abb abb bab bba bab bba"

/*
Questions:
    1. How can it tell a set of strings are a permutation?
    2. What are we passing into the function?
    3. How do we switch the characters around to create new strings?
    4. How do we store these new strings?
    5. What are we returning?

Assumptions:
    1. The program should run through each character in the string and store it in an array.
    2. The first letter in the string should be fixed while the other characters in the string switch
    3. A permutation starts at n, decreases by 1 until it gets to 0
*/ 
// Function to find all Permutations of a given string str[i..n-1]
// containing all distinct characters

void permutation(string str, int idx, int last){
// if the string of the index number and the string of the last number match, print the string
    if (idx == last - 1){
        cout << str << endl;
        return;
    }
    //use recursion for every character in the string, swap the index character with the current character
    for (int i = idx; i < last; i++){
        swap(str[idx], str[i]);
        permutation(str, idx + 1, last);
        //swap the string and putting it back
        swap(str[idx], str[i]);
    }
}

int main(){
    string palindromeStr;

    cout << "LONGEST SUBSTRING" << "\n" << "Enter a string of characters that includes a palindrome (a word you can read forwards and backwards): ";
    cin >> palindromeStr;
    cout << "\nLONGEST SUBSTRING: " + longestSubstring(palindromeStr) + "\n" << endl;

    cout << "STRING PERMUTATION" << "\n" << "Enter a string of characters: ";

    string str;
    cin >> str;
    cout << "\n" << "RESULT: " << endl;
    permutation(str, 0, str.size());
 
    return 0;
}