#include <iostream>
using namespace std;

/*This method will take in a string s and find the longest palindrome substring within the given string.
First, it will find the longest palindrome of odd length. Then it will find the longest palidrome of even length.
It will return which ever is the longest.*/
string lps(string s)
{
    // if the string has one or less characters, the string itself is the longest palindrome
    if (s.length() <= 0)
    {
        return s;
    }

    // otherwise, find the longest palindrome looping through the string
    else
    {
        string lp = ""; // variable to hold the longest palindrome
        // loop through the string char by char to find longest odd 
        for (int i = 0; i < (int)s.length(); ++i)
        {
            // make sure we aren't at the first or last char (they won't be palindromes)
            if ((i != 0) && (i != (int)s.length() - 1))
            {
                string cp = ""; // variable for the current palindrome
                cp = cp + s[i];
                // use these two variables to compare the chars on either side of the current char
                int j = i - 1; // checks the variable on the left
                int k = i + 1; // checks the variable on the right

                // must keep the palindrome between the string bounds
                while ((j >= 0) && (k <= (int)s.length() - 1))
                {
                    // if the chars on either side of the current side are equal, we fouud a palindrome
                    if (s[j] == s[k])
                    {
                        // build a new palindrome using the old palindrome plus the two new chars
                        cp = s[j] + cp + s[k];

                        // if the current palindrome is longer than our longest palidrome, set lp as cp
                        if ((int)cp.length() > (int)lp.length())
                        {
                            lp = cp;
                        }

                        // move back one on the left side and and forward one on the right side
                        --j;
                        ++k;
                    }
                }
            }
        }

        return lp;
    }
}

int main()
{
    // get a string from the user
    string message, palindrome;
    cin >> message;
    // pass the string to the lps method and print the string it returns
    palindrome = lps(message);
    cout << "The longest palindrome is: " << palindrome << endl;
    return 0;
}
