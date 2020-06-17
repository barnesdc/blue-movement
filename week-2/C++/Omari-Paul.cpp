#include <iostream>
using namespace std;

void permute(string str, int l, int r)
{
    if (l == r)
        cout << str << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]);
        }
    }
}

void palindrome()
{
    char word[50] = "madam";
    int length = strlen(word);
    int flag = true;

    for (int i = 0; i < length; i++)
    {
        if (word[i] != word[length - 1 - i])
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
        cout << "The word " << word << " is palindrome!";
    else
        cout << "The word " << word << " is not palindrome!";
}

int main()
{
    string str = "MIX";
    int n = str.size();

    permute(str, 0, n - 1);
    palindrome();
}