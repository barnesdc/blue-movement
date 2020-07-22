// C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

// helper function for problem 1
// start and last are inclusive
// thankfully everyday she finds at least 1 stone so there
// will never be duplicates in the aggregate array
int binarySearch(std::vector<int>& A, int start, int last, int tgt)
{
    if (last < start)
        return -1;

    int mid = ((last - start) / 2) + start;
    if (A.at(mid) == tgt) {
        return mid;
    }
    else if (start == mid) {
        if (A.at(mid) > tgt)
            return start;
        return last;
    }
    else if (A.at(mid) > tgt) {
        return binarySearch(A, start, mid, tgt);
    }
    else if (A.at(mid) < tgt) {
        return binarySearch(A, mid + 1, last, tgt);
    }
    else {
        return -1;
    }
}

// function for problem 1
void stoneLove(int n, int q, std::vector<int> A, std::vector<int> M)
{
    std::vector<int> aggregate = std::vector<int>();
    aggregate.push_back(A.at(0));

    for (int i = 1; i < n; i++)
        aggregate.push_back(aggregate.back() + A.at(i));

    for (int m : M)
        std::cout << binarySearch(aggregate, 0, n - 1, m) + 1 << std::endl;
}


// function for problem 2
void repeatedKTimes(int n, int k, std::vector<int> A)
{
    std::unordered_map<int, int> repeats = std::unordered_map<int, int>();

    for (int a : A)
    {
        if (repeats.count(a) == 0)
        {
            repeats.insert({ a,1 });
        }
        else {
            repeats.at(a)++;
        }
    }

    int min = -1;

    for (std::pair<int, int> r : repeats)
    {
        if (r.second == k)
        {
            if (min == -1 || min > r.first)
                min = r.first;
        }
    }

    std::cout << min << std::endl;
}

int main()
{
    std::vector<int> A = { 2, 2, 1, 3, 1 };
    repeatedKTimes(5, 2, A);
    repeatedKTimes(5, 1, A);
    A = { 2, 2, 1, 3, 1, 4, 4, 4, 4 };
    repeatedKTimes(9, 4, A);

    std::cout << std::endl;

    A = { 1, 2, 3, 4, 5 };
    std::vector<int> M = { 3, 8, 10, 14 };
    stoneLove(5, 4, A, M);
    std::cout << std::endl;
    A = { 3, 3, 5, 1 };
    M = { 1, 3, 8, 11, 12 };
    stoneLove(4, 5, A, M);
}


