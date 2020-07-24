# Promp1: Finding the Longest palindrome
word = input()
# maximum palindrome
max = 0

# Iterating through the string
for i in range(0,len(word)):
    # Iterating through all the possible substrings
     for j in range(i, len(word)):
        # Finding all possible substrings
         string1 = word[i:j+1]
        # Finding reverse of substrings
         string2 = string1[::-1]
        # Checking if both strings are palindromic and finding the maximum length
         if string1 == string2 and len(string1) > max:
             max = len(string1)
print(max)


# Prompt 2: Print all the permutations of str
# Importing python permutation library
from itertools import permutations 

# Assigning the list of permutations and joining the string when iterating
p = list(map("".join,permutations('str')))

# Iterating through the list of Permutations
for i in list(p):
    # Printing and eliminating new lines
    print(i, end = '  ')
