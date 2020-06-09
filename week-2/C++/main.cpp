#include <iostream>
#include <array>
using namespace std;

bool isPalindrome(string str){
  int length = str.length();
  for(int i = 0; i< length; i++)
  {
    if(str[i] != str[length - i - 1])
      return false;
  }
  return true;
}

string longest_substring(string str){
  int len = str.length(); //13
  int first, len_of_substr = len;
  bool yes = false;
  string hold = "";
  string s = "";

  for (int i = 1; i <= len; i++)
  {
    first = 0;
    for(int j = 0; j < i; j++)
    {
      /*
      if(last < 10) cout<<' ';
      cout<<first<<" - "<<last<< "   ";
      */
      s = str.substr(first, len_of_substr);
      if(isPalindrome(s))
      {
         hold = hold + s +' ';
         yes = true;
      }
      first++;
    }
    len_of_substr--;
    if(yes) return hold;
  }

  return "";
}

int main(){
  //cout << (isPalindrome("alab")? "true" : "false");
  string str = {"lol"}, holder;
  holder = longest_substring(str);
  cout<<holder;
  return 0;
}

/*Method: Find every possible substring
from biggest to smallest. CHeck if a palindrome,
add it to returning string.
*/
