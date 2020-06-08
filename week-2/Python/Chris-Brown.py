#!/usr/bin/env python3

from itertools import permutations
import argparse


#Define a funtion isPalendrome() to do a check on a string
def isPalindrome(s):

    #reverse the string then check if its equal
    reverse = s[::-1]

    if reverse == s:
        return True

    else:
        return False

#Now use isPalindrome() to check a substring in this function
def longestPal(s):

    longest = ''
    sub = ''

    for ch in s:

        #add one character at a time to sub then check
        sub += ch

        if isPalindrome(sub):
            longest = sub

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
