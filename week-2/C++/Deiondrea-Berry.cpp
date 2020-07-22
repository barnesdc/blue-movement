#include <iostream>
#include <algorithm>
using namespace std;

//factorial
int fact(int n){
  if(n < 1) return 1;
  else return n* fact(n-1);
}

//check if string is palindrome
bool isPalindrome(string str){
  int length = str.length();
  //comparing letters inward to see if they match
  for(int i = 0; i< length; i++)
    if(str[i] != str[length - i - 1])
      return false;
  return true;
}

//find longest substring and return it
string longest_substring(string str){
  int first,
      len = str.length(),
      len_of_substr = len;
  bool yes = false;
  string hold = "", s = "";

  /*get all substrings of string from biggest
  size (size of string) to smallest (1 char).
  */
  for (int i = 1; i <= len; i++)
  {
    first = 0;
    for(int j = 0; j < i; j++)
    {
      //length of substring goes from len to 1
      s = str.substr(first, len_of_substr);

      /*
      //print this to see substring indexes
      if(last < 10) cout<<' ';
      cout<<first<<" - "<<last<< "   ";
      */

      //check if each string is a palindrome
      if(isPalindrome(s))
      {
        //concatentate hold with each palindrome substring
         hold = hold + s +' ';
         yes = true;
      }
      first++;
    }
    len_of_substr--;
    //if found a palindrome substring return it
    if(yes) return hold;
  }
  return "";
}

//find and print all permutations of string
void permutations(string s){
  //find number of permutations
  int num = fact(s.length());

//
  for(int i = 0; i< num; i++)
  {
    next_permutation(s.begin(),s.end());
    cout<<i + 1<< ": "<< s << endl;
  }
}

int main(){
  string holder, str;
  str = "bababa";
  holder = longest_substring(str);
  cout<<"The longest substring in "<< str << " is: "<< holder<<endl;

  str = "abcs";
  cout<< "Permutations for "<< str<< ":\n";
  permutations(str);

  return 0;
}
