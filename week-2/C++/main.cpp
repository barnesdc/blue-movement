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
  int first, last;
  bool yes = false;
  string hold = "";
  string s = "";


  for (int i = 1; i <= len; i++)
  {
    first = 0;
    last = len -i; //12 11 10
    for(int j = 0; j < i; j++)
    {
      s = str.substr(first, last);
      if(isPalindrome(s))
      {
         hold = hold + s +' ';
         yes = true;
      }
      first++;
      last++;
    }
    if(yes) return hold;
  }

  return "";
}

int main(){
  //cout << (isPalindrome("alab")? "true" : "false");
  string str = {"djbubpiltitld"}, holder;
  holder = longest_substring(str);
  cout<<holder;
  return 0;
}

//djbubpiltitla doesnt work but djbubpiltitl does.
