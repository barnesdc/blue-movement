#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int[],int, int);
void queries(int[],int, int[], int);
int smallestKthRepeat(vector<int>, int);
int main(){
  cout << "\tPrompt 1" << endl;
  int array1[] = {1,2,3,4,5}, array2[] = {3,8,10,14}; //change values here

  const int arr1sz = sizeof(array1)/sizeof(array1[0]); //num of days
  int sumArr[arr1sz], sum = 0;

  for(int i = 0; i< arr1sz; i++) sum += array1[i]; //sum 4each day
  sumArr[arr1sz-1] = sum; //index 5 = sum
  //sum value index 4 =  new sum which equals 15 (sum)-5(index 5) -> 1 3 6 10 15
  for(int i = arr1sz-2; i >= 0; --i) sumArr[i] = sum -=array1[i+1];

  queries(sumArr, arr1sz, array2, sizeof(array2)/sizeof(array2[0]));

  cout<<"\n\tPrompt 2" <<endl;
  vector<int> vec= {2,1,3,1,2}; //change values here
  int timesRepeated = 2; //change values here

  cout << "The smallestKthRepeat is: "
        << smallestKthRepeat(vec, timesRepeated) <<endl;

  return 0;
}

//binarySearch the sum array for each value in the query array(qarr)
void queries(int arr[],int arr1len,int qarr[], int qarrlen){
	for(int i = 0; i< qarrlen; i++)
		cout << binarySearch(arr, arr1len, qarr[i])<<endl;
}
//returns index + 1  of value  or index of value right above
int binarySearch(int arr[],int sz, int key ){

   bool isFound = false;
	int mid, small = 0, large = sz-1;

	while(small <= large && isFound == false){
		mid = (large + small)/2;

		if(arr[mid] > key)
			large = mid - 1;
		else if(arr[mid]< key)
			small = mid+1;
		else{
			isFound = true;
			return mid +1;
		}
	}
	if (!isFound) return mid + 1;
  else return -1;
}
//Sorts and checks for repeats, compare repeats to reps var
int smallestKthRepeat(vector<int> vec, int reps){
  vector<int>::iterator i = vec.begin(), j = vec.end();
  sort(i, j);

  int count = 1;
  i = vec.begin() +1;

  for(i; i != j; ++i){ //get counts
    int current = (*i), last = (*(i-1)); //start at 1 and peek back
    if(current == last) count++; //counts number of repeated for each #
    else
      if(count == reps) return last; // if count of last # == reps
      else count = 1; //if on new # and old count isnt correct, reset
  }

  //if at end, answer must be last value bc a true answer exists
  if(count == reps)
    return vec.back();
  else return -1; //if something went wrong
//nlogn + n
}
