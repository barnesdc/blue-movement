# Given a string, find the longest substring which is palindrome. For example, if the given string is "ababad", the output should be "ababa".
def longest(s):
    palindrome = ''
    for i in range(1, len(s) + 1):
        for j in range(len(s) - i + 1):
            ss = s[j:j + i]
            if isPalindrome(ss) and len(ss) > len(palindrome):
                palindrome = ss
    return palindrome


def isPalindrome(s):
    s_reverse = s[::-1]
    if s == s_reverse:
        return s
    else:
        return None


string = longest("ababad")
print(string)

# Given a string str, the task is to print all the permutations of str. A permutation is an arrangement of all or part of a set of objects, with regard to the order of the arrangement. For example, if given "abb", the output should be "abb abb bab bba bab bba"
from itertools import permutations

string = "abb"

lists = permutations(string)

for i in list(lists):
    print(''.join(i), end=' ')
