#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
using namespace std;

int fact(int n)
{
  if(n < 1) return 1;
  else
      return n* fact(n-1);
}

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
void permutations(string s){
  //vector<char> each_perm = s;
  int num = fact(s.length());

  for(int i = 0; i< num; i++)
  {
    next_permutation(s.begin(),s.end());

    cout<<setw(4)<<i + 1<< ": "<< s << endl;

  }

}
int main(){
  //cout << (isPalindrome("alab")? "true" : "false");

  string holder, str;
  str = "bababa";
  holder = longest_substring(str);
  cout<<"The longest substring in "<< str << " is: "<< holder<<endl;

  str = "abcs";
  cout<< "Permutations for "<< str<< ":\n";
  permutations(str);

  return 0;
}

/*Method: Find every possible substring
from biggest to smallest. CHeck if a palindrome,
add it to returning string.
*/
