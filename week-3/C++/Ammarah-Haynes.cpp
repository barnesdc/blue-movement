//hacker rank
#include <iostream>
#include <string>
#include <string.h>
#include <array>
using namespace std;

int maxSpread(){

  int array [3] = {4,9,28};
  int size = sizeof(array)/ sizeof(array[0]);
  int temp = 0;
  int max = -1;

  for (int i = 1; i < size; i++){
    cout << "Hello i = " << i << endl;

    for (int j = i; j >= 0; j--){
      if (array[i] > array[j]){
        temp = array[i] - array[j];
        if (temp > max)
           max = temp;
      }
      cout << "node = " << array[i] << endl;
      cout << "Previous = " << array[j] << endl;
    }
  }
  return max;
}
int main(){

  cout << maxSpread();

  return 0;
}
