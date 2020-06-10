#include <iostream>

using namespace std;

void palindrome()
{
    char str[100] = "madam";
    int length = strlen(str);
    int flag = true;

    for (int i = 0; i < length; i++)
    {
        if (str[i] != str[length - 1 - i])
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
        cout << "The word " << str << " is palindrome!";
    else
        cout << "The word " << str << " is not palindrome!";
}

int main()
{
    palindrome();
}
