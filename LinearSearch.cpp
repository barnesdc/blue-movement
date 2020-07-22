#include <iostream>
#include <vector>
#include <map>

using namespace std;


int linear(int k, vector<int> list) {
  int count = 0;
  int min = list[0];
  vector<int> kVals;
  map<int, int> m;
  for(int i = 0; i < list.size(); i++) {
    if(m[list[i]] >= 1) {
      m[list[i]]++;
    }
    else {
      m[list[i]] = 1;
    }
  }

  for(auto it: m) {
    if(it.second == k) {
      kVals.push_back(it.first);
    }
  }
  /*
  for(int i = 0; i < list.size(); i++) {
    if(min == list[i]) {
      count++;
      if(count == k) {
        kVals.push_back(min);
      }
    }
  }
  */
  cout << "----------" << endl;
  for(int i = 0; i < kVals.size(); i++) {
    cout << kVals[i] << endl;
  }

  cout << "----------" << endl;
  int minKVal = kVals[0];
  for(int i = 0; i < kVals.size(); i++) {
      if(minKVal > kVals[i]) {
          minKVal = kVals[i];
      }
  }
  return minKVal;
}


int main() {
  int n;
  vector<int> list;
  cin >> n;
  cout << "--" << endl;
  for(int i = 0; i < n; i++) {
    int number;
    cin >> number;
    list.push_back(number);
  }
  cout << "--" << endl;
  int k;
  cin >> k;

  cout << linear(k, list) << endl;
 

  return 0;
}
