#include <iostream>

// using namespace std;

// dynamic programming problem
std::string longPalSubstr(std::string str)
{
	int n = str.length();
	bool isPal[n][n];

	int a, b = 0;

	// i will be the starting index and j will be the ending index
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) {
				// bsae case: m = 1
			    isPal[i][j] = true;
			} else if (j - i == 1 && str[i] == str[j]) {
				// bsae case: m = 2
			  	isPal[i][j] = true;
			  	a = i;
			  	b = j;
			} else {
			    isPal[i][j] = false;
			}
		}
	}

	if (n > 2)
	{
		// let m be the size of the substring
		for (int m = 3; m <= n; m++)
		{
			int i = 0;
			int j = m - 1;
			while (j < n)
			{
				isPal[i][j] = (str[i] == str[j]) && isPal[i+1][j-1];
				if (isPal[i][j] && m > b - a + 1)
				{
					a = i;
					b = j;
				}
				i++;
				j++;
			}
		}
	}
  
	return str.substr(a, b - a + 1);
}

int main(int argc, char const *argv[]) {
	std::cout << "Given a string, find the longest substring which is palindrome. For example, if the given string is ababad, the output should be ababa." << std::endl << std::endl;

	std::string input = "ababad";
	std::string output = longPalSubstr(input);

	std::cout << output << std::endl;
}