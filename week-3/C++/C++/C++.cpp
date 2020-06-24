// C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


string maxSubstringWrong(string s) {
    int n = s.length();

    if (n == 0)
        return s;

    char maxC = 'a' - 1;
    std::vector<int> maxInds = std::vector<int>();
    int maxCInd = -1;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == maxC) {
            maxInds.push_back(i);
        }
        else if (s.at(i) > maxC) {
            maxInds.clear();
            maxC = s.at(i);
            maxInds.push_back(i);
        }
    }

    // need a smart way to determine which is the correct substring in maxInds
    int maxInd = maxInds.size() - 1;
    for (int i = maxInds.size() - 1; i > 0; i--) {
        if (s.substr(maxInds[maxInd], n - maxInds[maxInd]) <= s.substr(maxInds[i - 1], n - maxInds[i - 1])) {
            maxInd = i;
        }
    }
    return s.substr(maxInd, n - maxInd);

}



/*
 * Complete the 'maxSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string maxSubstring(string s) {
    int n = s.length();
    string maxStr = "";
    for (int i = 0; i < n; i++) {
        if (maxStr < s.substr(i, n - i))
            maxStr = s.substr(i, n - i);
    }
    return maxStr;
}

int main()
{
    std::cout << maxSubstring("aaa") << std::endl;
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
