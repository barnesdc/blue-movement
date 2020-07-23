//hacker rank problem. Solved 11/15 test cases

#include <iostream>
#include<string>
#include<vector>

using namespace std;

string partitioningArray(int k, vector<int> numbers){
  int size = numbers.size();
  if (size % k == 0){
    for(int i = 0; i < size; i+=2){
      for(int j = i+1; j < size; j+=2){
        if(numbers[j] == numbers[i])
          return "No";
        break;
      }
    }
    return "Yes";
  }
  return "No";
}

int main(){
  int k, n, values = 0;
  vector<int> numbers;

  cout << "Enter k: ";
  cin >> k;

  cout << "Enter size of vector: ";
  cin >> n;

  cout << "Enter vector values: ";
  for(int i = 0; i < n; i++){
    cin >> values;
    numbers.push_back(values);
  }

  cout << partitioningArray(k, numbers);

  return 0;
}
