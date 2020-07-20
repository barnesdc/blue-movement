#include <iostream>
using namespace std;

int binarySearch(int arr[],int, int);
void queries(int[],int, int[], int);

int main(){
  int array1[] = {1,2,3,4,5},
      array2[] = {3,8,10,14};

  const int arr1sz = sizeof(array1)/sizeof(array1[0]); //num of days
  int sumArr[arr1sz], sum = 0;

  for(int i = 0; i< arr1sz; i++) sum += array1[i]; //sum 4each day

  sumArr[arr1sz-1] = sum; //index 5 = sum
  for(int i = arr1sz-2; i >= 0; --i)
    sumArr[i] = sum -=array1[i+1]; 
    //change sum value index 4 =  new sum which equals 15 (sum)-5(index 5) -> 1 3 6 10 15

  queries(sumArr, arr1sz, array2, sizeof(array2)/sizeof(array2[0]));

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
