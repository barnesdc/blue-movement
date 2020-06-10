# -*- coding: utf-8 -*-
"""
Created on Tue Jun  9 21:12:27 2020

@author: andre
"""


def palindrome_helper(string, left_char, right_char, longest_len, first_char):
    '''moves outward to determine longest palindrome'''
    string_len = len(string)
    # check to stay within bounds of string
    # also checks that left and right characters are the same
    while left_char >= 0 and right_char < string_len and (string[left_char]
                                                          == string[right_char]):
        # length of substring
        current_length = right_char - left_char + 1
        if current_length > longest_len:
            # update stats
            first_char = left_char
            longest_len = current_length
            # move outwards
        left_char -= 1
        right_char += 1
    return [longest_len, first_char]


def longest_palindrome(string):
    # Using first character as a palindrome
    first_char = 0
    # single character is a palindrome
    longest_len = 1

    # initializing the two characters looked at to determine palindrome
    left_char = 0
    right_char = 0

    # will move right and outwards to determine palindromes
    for x in range(0, len(string) - 1):
        # even palindromes
        left_char = x
        right_char = x + 1
        info = palindrome_helper(string, left_char, right_char,
                                 longest_len, first_char)
        longest_len = info[0]
        first_char = info[1]

        # odd length palindromes
        left_char = x
        right_char = x + 2
        # repeat process but assume palindrome has char in the middle
        info = palindrome_helper(string, left_char, right_char,
                                 longest_len, first_char)
        longest_len = info[0]
        first_char = info[1]
    return string[first_char: first_char + longest_len]


def one_swap(string_array, start, end, final_array):
    if start != end:
        place_holder = string_array[end]
        string_array[end] = string_array[start]
        string_array[start] = place_holder
        final_array += [string_array[:]]
        one_swap(string_array, start + 1, end, final_array)
        return final_array
    else:
        return string_array


def permutations(string):
    start = 0
    end = len(string) - 1
    string_array = []
    for letter in string:
        string_array += [letter]
    final_array = []
    for x in range(start, end + 1):
        one_swap(string_array, start, end, final_array)
    for z in range(len(final_array)):
        str = ""
        for letter in final_array[z - 1]:
            str += letter
        final_array[z - 1] = str
    print(final_array)
