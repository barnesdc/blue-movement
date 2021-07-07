//************************************************
// Longest Substring, String Permutation
// Event: Week 2 - IBM Blue Movement 
// Name: Hezekiah Branch
// Date: June 07, 2020
// Purpose: Finds the longest palindrome substring in a target
// and prints all permutations of a given string
// Prompt(s)
// - Given a string, find the longest substring which is palindrome. 
//   For example, if the given string is "ababad", the output should be "ababa".
// - Given a string str, the task is to print all the permutations of str.
//   A permutation is an arrangement of all or part of a set of objects, with 
//   regard to the order of the arrangement.
//   For example, if given "abb", the output should be 
//   "abb abb bab bba bab bba"
//
// Source for suffix tree (+compressed) theory: 
// Suffix Trees, Carnegie Mellon University, Professor Carl Kingsford
// https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/suffixtrees.pdf
// Ben Langmead for 9/25/2013 in EN 600.439/639: Computational Genomics
// https://www.youtube.com/watch?v=hLsrPsFHPcQ
//
// Updates: Still need to finish developing Suffix Tree but
// the is_palindrome function is working well
//************************************************

#include <iostream>
#include <string>

#include <ctype.h> 
#include <stdio.h> 

#include <vector>
#include <unordered_map>

using namespace std;

// Function prototypes
bool is_palindrome(string); // Checks if palindrome
string max_substring(string); // Finds longest palindrome
void print_permutation(string); // Prints permutations
string swap_letters(string word, int a, int b); // Swap two letters in a word, useful for permutations


// Test cases
string true_palindromes[16] = { "ababa", "Anna", "Civic", "Kayak", "Level",
"Madam", "Mom", "Noon", "Racecar", "Rotator", "Rotor", "Sagas", "Solos",
"Stats" };

string false_palindromes[16] = { "ababad", "joker", "batman", "robin", 
"superman","lex", "123", "canary", "deathstroke", "harley", "wonder woman",
"flash", "starfire", "beast" };

// Suffix Tree Class
class SuffixTree 
{

	struct SuffixNode {
		char value;
		vector<SuffixNode> children;
	};

	public:
		SuffixTree(string t) {
			// Sentinel symbol
			t.append("$");
			int length = t.size();
			// Traverse through each suffix
			for (int idx = 0; idx < length; idx++) { // Range of t's length
				vector<SuffixNode> * current = &root;
				// Each letter in the current suffix
				int splice = idx;
				while (splice < length) {
					char letter = t[splice];
					if (contains(root, letter)) {
						//current[letter] = {};
					}
				} // end inner while loop
			} // end outer for loop
		}

		bool contains(vector<SuffixNode> root, char letter)
		{
			bool found = false;
			for (auto item : root) {
				if (item.value == letter) {
					found = true;
					return found;
				}
			}
			return found;
		}

	private:
		vector<SuffixNode> root;
};

int main()
{
	// Prompt 1 Solution
	// Build a compressed suffix tree to query substrings
	// Find longest substring that is a palindrome
	// Use is_palindrome() to check if palindrome
	cout << "Enter a string to find the longest substring that is a palindrome: ";
	string target;
	cin >> target;
	if (is_palindrome(target)) {
		cout << target << " is a palindrome!" << endl;
	} else {
		cout << "Not a palindrome." << endl;
	};

	// Prompt 2 Solution
	// Print all permutations
	cout << endl << "************************************************************" << endl;
	cout << "Enter a string to permute: ";
	string to_permute;
	cin >> to_permute;
	print_permutation(to_permute);
}

// Determines if the string is a palindrome
// Return type: Boolean
// Input: String
// Effects: None
// Notes: Helper function
bool is_palindrome(string word)
{
	bool is_palindrome = true;
	word[0] = tolower(word[0]);

	int left = 0;
	int right = word.size() - 1;
	while (left <= right) {
		if (word[left] != word[right]) {
			is_palindrome = false;
		}
		left += 1;
		right -= 1;
	}
	return is_palindrome;
}

// Prints all permutations of a string
// Return type: Void
// Input: String
// Effects: None
// Notes: Need to reduce time complexity from O(n**2)
void print_permutation(string word)
{
	for (int i = 0; i < word.size(); i++) {
		for (int j = 0; j < word.size(); j++) {
			if (j != i) {
				word = swap_letters(word, i, j);
				cout << word << endl;
				word = swap_letters(word, j, i);
			}
		}
	}
}

// Swaps two characters in a string
// Return type: string
// Input: string word, int index1, int index2
// Effects: None
// Notes: Helper function, helpful for Cartesian product
// May be more useful to use string pointers here
string swap_letters(string word, int a, int b) 
{
	char temp = word[a];
	word[a] = word[b];
	word[b] = temp;
	return word;
}