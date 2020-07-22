#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct T {
    long data;
    long count;
};

// Main function containing solution to problem 2
int main () 
{
    // Get total size of vector needed
    long size; 
    cin >> size;
    vector<T> values(size + 1);
    // Get input values
    long input;
    while (size > 0) {
        cin >> input;
        if (values[input].count > 0) {
            values[input].count += 1;
        } else {
            T object;
            object.data = input;
            object.count = 1;
            values[input] = object;
        }
        size -= 1;
    }
    // Get K from input space
    long k; cin >> k;
    // Check values
    long min = 100001;
    for (auto object : values) {
        if (object.count == k && object.data < min) {
            min = object.data;
        }
    }
    cout << min;
    return 0;
}