#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void binary(vector<int> stones, queue<int> dayStones) {
  vector<int> output;
  while(!(dayStones.empty())) {
    int countDays = 0;
    int countStones = 0;
    int i = 0;
    while(!(dayStones.front() <= countStones)) {
      countDays++;
      countStones += stones[i];
      i++;
    }
    output.push_back(countDays);
    dayStones.pop();
  }

  for(int i = 0; i < output.size(); i++) {
    cout << output[i] << endl;
  }


}


int main() {
  int days, queries;
  vector<int> stones;
  queue<int> dayStones;
  cin >> days;
  cin >> queries;

  for(int i = 0; i < days; i++) {
    int n;
    cin >> n;
    stones.push_back(n);
  }

  for(int i = 0; i < queries; i++) {
    int m;
    cin >> m;
    dayStones.push(m);
  }

  binary(stones, dayStones);
  
  return 0;
}
