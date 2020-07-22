
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string palindrome(string word) {
  vector<string> container;
  string final_word;
  for(int i = 0; i <= word.size() - 1; i++) {
    for(int j = word.size() - 1; j >= i; j--) {
      int tempI = i;
      int tempJ = j;
      if( ((tempJ - tempI) % 2) + 1 == 1) {
	while(!(i == j) && word.at(i) == word.at(j)) {
	  i++;
	  j--;
	}
	if((i == j) && word.at(i) == word.at(j)) {
	  container.push_back(word.substr(tempI, (tempJ - tempI) + 1));
	}
      }
      else if(((tempJ - tempI) % 2) + 1 == 2) {
	while(!(i+1 == j) && word.at(i+1) == word.at(j)) {
	  i++;
	  j--;
	}
	if((i+1 == j) && word.at(i+1) == word.at(j)) {
	  container.push_back(word.substr(tempI + 1, (tempJ - tempI) + 1));
	}	
      }
    }
  }

  final_word = container[0];
  for(int i = 1; i < container.size(); i++) {
    if(final_word.size() < container[i].size()) {
      final_word = container[i];
    }
  }
  return final_word;  
}

void permutations(string word, int beg, int end) {
  if(beg == end - 1) {
    cout << word << endl;
    return;
  }
  else {
    for(int i = beg; i < end; i++) {
      swap(word[beg], word[i]);
      permutations(word, beg + 1, end);
      swap(word[beg], word[i]);
    }
  }
}


int main() {
  string word;
  cin >> word;
  cout << "----------" << endl;
  cout << "The longest palindrome is: " << palindrome(word) << endl;
  permutations(word,0,word.length());
  return 0;
}
