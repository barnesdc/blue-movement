from itertools import permutations

#Define a funtion isPalendrome() to do a check on a string
def isPalindrome(s):

    #reverse the string then check if its equal
    reverse = s[::-1]

    if reverse == s:
        return True

#Now use isPalindrome() to check a substring in this function
def longestPal(s):

    longest = ''
    sub = ''

    for ch in s:

        #add one character at a time to sub then check
        sub += s

        if isPalindrome(sub) == True:
            longest = sub

    return longest


######################################################################################


#I am using the itertools library to find permutations

def printPermutations(s):

    perm = Permutations(s)

    for i in perm:
        print(i)
