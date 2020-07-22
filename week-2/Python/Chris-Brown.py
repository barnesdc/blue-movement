#!/usr/bin/env python3

from itertools import permutations
import argparse


#Now use isPalindrome() to check a substring in this function
def longestPal(s):

    longest = ''
    max = 1

    start = 0

    low = 0
    high = 0

    for i in range(1, len(s)):
        low = i - 1
        high = i

        while low >= 0 and high < len(s) and s[low] == s[high]:
            if high - low + 1 > max:
                start = low
                max = high - low + 1
            low -= 1
            high += 1

        low = i - 1
        high = i + 1
        while low >= 0 and high < length and s[low] == s[high]:
            if high - low + 1 > max:
                start = low
                max = high - low + 1

            low -= 1
            high += 1

    longest = s[start:start + max]
    return longest


######################################################################################


#I am using the itertools library to find permutations

def printPermutations(s):

    perm = permutations(s)
    result_list = []

    for i in perm:
        x = ''.join(i)
        result_list.append(x)

    print(' '.join(result_list))


if __name__ == '__main__':
    ap = argparse.ArgumentParser(description='From File -F or Text input -T')
    ap.add_argument("-F", "--file", required=False, type=str, help='filename')
    ap.add_argument("-T", "--text", required=False, type=str, help='text input')
    args = ap.parse_args()
    if args.file:
        palindrom = open(args.file, 'r')
        for line in palindrom:
            print(isPalindrome(args.file))
            print(longestPal(args.file))
            printPermutations(args.text)
    elif args.text:
        print(isPalindrome(args.text))
        print(longestPal(args.text))
        print()
        printPermutations(args.text)
    else:
        print("ERROR: No Input")
        exit(1)
