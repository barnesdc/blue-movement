
#include <iostream>
#include <algorithm>    // std::sort
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Function Prototypes
// Populate vectors with data from provided input
void preload_vectors(vector<int> * s, vector<int> * q);
// Binary search implementation
void binary_search(int target); 

// Main function containing solution
int main () 
{
    // Container for number of stones + queries
	vector<int> stones;
    vector<int> queries;
    preload_vectors(&stones, &queries);
    // Start checking the queries
    queue<int> found;
    for (auto stone : stones) {
        cout << stone << " ";
    }
	return 0;
}

// ----------------------------------------------------------------

// Preload Vectors
// Parameters: Int vectors of stones and queries
// Purpose: Populate vectors with user input of stone info
// Runtime: O(length of stones + length of queries)
void preload_vectors(vector<int> * stones, 
                   vector<int>  * queries)
{
    // Get input of days and queries
	int days; 
    int query_count;
	cin >> days; 
    cin >> query_count;
    // Input values as integers
    int t; int q;
	while (days > 0) {
        cin >> t;
		stones -> push_back(t);
        days -= 1;
	}
    while (query_count > 0) {
        cin >> q;
        queries -> push_back(q);
        query_count -= 1;
    }
    // Sort the vector of stones O(nlogn)
    sort(stones -> begin(), stones -> end());
}

// Binary Search
// Parameters: int (to search for), vector<int> list
// Purpose: Rapidly find an element in a sorted list 
// Runtime: O(logn)
void binary_search(int target, vector<int> * list) 
{
    cout << "LOADING BINARY SEARCH..." << endl;
}
