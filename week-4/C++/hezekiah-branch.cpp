/********************************************
* IBM Blue Movement
* Week 4
* Hezekiah Branch
* 06/20/2020
* 
* LinkedList <T> Driver
* Driver file for the list ADT
*********************************************/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
#include <deque>

// Location of template definitions
#include "LinkedList.h"

using namespace std;

// Function prototypes
LinkedList<char> sum_list(LinkedList<int>, LinkedList<int>);
void reverse_list(LinkedList<char>);
void display_solution1(const vector<int> &A, const vector<int> &B);
void display_solution2(char * A, int size);

int main() 
{
    // Solution for Prompt #1
    cout << "Prompt #1" << endl;
    cout << "Given two numbers represented by two linked lists, write a function " << endl << 
	"that returns sum list. The sum list is a linked list representation" << endl << 
	"of addition of two input numbers.\n" << endl;
    // Test case for the first challenge
    vector<int> test1A = {5};
    vector<int> test1B = {9, 4};
    display_solution1(test1A, test1B);

    // Solution for Prompt #2
    cout << "Prompt #2" << endl;
    cout << "Given a linked list which represents a sentence S such that each node" << 
	"represents a letter, the task is to reverse the sentence without reversing individual words.\n" << endl;
    // Test case for the second challenge
    const int size = 22;
    char test2A[size] = {
        'I', '\0', 'l', 'o','v','e','\0', 'G', 'e','e','k','s', 
        '\0', 'f','o','r', '\0','G','e','e','k','s'
        };
    display_solution2(test2A, size);
    // Indicates solution working properly
    return 0;
}

LinkedList<char> sum_list(LinkedList<int> A, LinkedList<int> B)
{
    string a = "";
    string b = "";
    LinkedList<char> sum_list;
    for (int i = 1; i <= A.size(); i++) {
        int elem = A.elementAt(i);
        a += to_string(elem);
    }
    for (int i = 1; i <= B.size(); i++) {
        int elem = B.elementAt(i);
        b += to_string(elem);
    }
    int a_int = stoi(a);
    int b_int = stoi(b);
    int sum = a_int + b_int;
    string str_sum = to_string(sum);
    for (auto elem: str_sum) {
        sum_list.insert(elem);
    }
    sum_list.print();
    return sum_list;
}

void display_solution1(const vector<int> &A, const vector<int> &B)
{
    // Create Linked List and input values
    LinkedList<int> L1; LinkedList <int> L1B;
    for (auto num : A) {
        L1.insert(num);
    }
    for (auto num : B) {
        L1B.insert(num);
    }
    // Display size of list for correctness
    cout << "List 1: "; L1.print();
    cout << "List 2: "; L1B.print();
    cout << endl;
    cout << "Sum of the lists: " << endl;
    sum_list(L1, L1B);

    cout << endl;
    // Destroy the lists
    L1.terminate(); L1B.terminate();
}

void display_solution2(char * A, int size)
{
    // Create deque adding each space-separated phrase to it 
    deque<char> backwards;
    stack<char> ordered;
    // Preserve order and add letters to deque
    for (int idx = 0; idx <= size; idx++) {
        if (A[idx] == '\0') {
            while (!ordered.empty()) {
                char elem = ordered.top();
                backwards.push_front(elem);
                ordered.pop();
            }
            backwards.push_front(A[idx]);
        } else {
            ordered.push(A[idx]);  
        }
    }
    backwards.pop_front();
    // Convert deque to linked list of characters
    LinkedList<char> sentence;
    while (!backwards.empty()) {
        char elem = backwards.front();
        sentence.insert(elem);
        backwards.pop_front();
    }
    // Print list and deallocate memory
    sentence.print();
    sentence.terminate();
}