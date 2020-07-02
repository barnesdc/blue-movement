#include <iostream>
#include <string>
using namespace std;

//palindrome
int main(){
  string str = "ebcdcbn";
  int len = str.size()- 1;
  int j = len;
  int i = 0;

  while (i != j) {     //str. for(int i = 0; i < str.size(); i++){
    if(str[i] == str[str.size()-1]){
      ++i;
      --j;
    }
    else{

    }
  }
  cout << str;

  return 0;
}
//Permutations
