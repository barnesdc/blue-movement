#include <iostream>
#include <string>
#include <vector>
#include <algortithm>
using namespace std;

int main (){
  int n, value, finalprice = 0;
  vector<int> prices;
  vector<int> fullPrice;
  vector<int> discountedPrices;


  cout << "Enter the size of the vector: " << endl;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> value;
    prices.push_back(value);
  }

  for(int i = 0; i < n; i++){
    bool found = true;
    for(int j = i+1; j < n; j++){
      if(prices[j] <= prices[i]){
        discountedPrices.push_back(prices[i] - prices[j]);
        found = false;
        break;
      }
    }
    if(found == true){
      discountedPrices.push_back(prices[i]);
      fullPrice.push_back(prices[i]);
    }
  }
  for(int i = 0; i < n; i++){
    finalprice += discountedPrices[i];
  }
  cout << finalprice << endl;

  sort(fullPrice.begin(), fullPrice.end());
  for(int i = 0; i < fullPrice.size(); i++){
    cout << fullPrice[i] << " ";
  }

  return 0;

}
