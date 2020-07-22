//FIRST PROMPT
#include <iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int num, q, m, s;
	cin >> num;
	cin >> q;

	vector<int> second;
	vector<int> third;

	for(int i = 0; i < num; i++){
		cin >> m;
		second.push_back(m);
	}
	for(int i = 0; i < q; i++){
		cin >> s;
		third.push_back(s);

	}

	for(int i = 0; i < q; i++){
		int sum = 0;
		for(int j = 0; j < num; j++){
			sum +=second.at(j);
			if (sum >= third.at(i)){
				cout << j + 1 << endl;
				break;
			}

		}
	}
  /*
sample input:
5 4
1 2 3 4 5
3 8 10 14

sample output:
2
4
4
5
*/

//Second prompt(NOT FINISHED)
#include <iostream>
#include<vector>
#include<string>
#include <algortithm>


using namespace std;

int main() {
	vector<int> list;
	int num, value, k,
	int seen = 0;
	cin >> num;
	//cout << num << endl;

	for(int i = 0; i < num; i++){
		cin >> value;
		list.push_back(value);
	}
	// for(int i = 0; i < num; i++){
	// 	cout << list.at(i) << " ";
	// }
	// cout << endl;

	cin >> k;
	// cout << k;

	// # of times integer repeats
	sort(list.begin(), list.end());
	for(int i = 0; i < num; i++){
		if(list.at(i) == list.at(i+1))

  /*
TO FINISH, I WOULD KEEP TRACK OF THE NUMBER OF OCCURRENCES FOR EACH NUMBER, THEN
COMPARE THAT NUMBER TO K. LASTLY, FIND THE SMALLEST NUMBER THAT OCCURS K # OF TIMES
  */

	}
	return 0;
}
