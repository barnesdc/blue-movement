#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int num;
    int nque;
    int q;
    int total=0;
    vector<int> que;
    cin >> num;
    cin >> nque;
for(int i=0; i <num; i++){
int temp;
cin >> temp;
total+=temp;
que.push_back(total);
}
 
    for(int i=0; i< nque;i++){
    cin >> q;
    int l=0;
    int r =que.size();
   while (l <= r) {
          int m = (l + r) / 2;
      
   if ( q > que[m-1] && q <= que[m] ){
           cout << m+1 <<endl;
           break;
       }
          // Check if x is present at mid
        else if (que[m] < q && q <= que[m+1]){
              cout << m+2<<endl;
            break;
       }
          // If x greater, ignore left half
          else if (que[m] < q)
              l = m + 1;
    
          // If x is smaller, ignore right half
          else
              r = m - 1;
      }
        
        #include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
 
int main() {
	int size;
	vector<int> arr;
	int rep;
	int count =1;
	cin >> size;										
	for(int i=0; i<size; i++){
	int temp;
	cin >> temp;
	arr.push_back(temp);
	}
	cin >> rep;
	sort(arr.begin(),arr.end());
	for(int j=0;j<size;j++){
	if(arr[j]==arr[j+1])
		count++;
	else{
		if(count==rep){
		cout<<arr[j];
		break;}
		else
		count=1;
 
	}
	}	
 
 
 
 
 
 
 
}
