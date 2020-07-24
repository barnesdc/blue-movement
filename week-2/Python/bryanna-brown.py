
# Find Palindrome finds

"""
This function returns true if the given string
is a palindrome and false other wise
"""
def findPalindrome(string):
    # even or odd number of characters?
    strLength = len(string)
    if (strLength % 2) == 0:
        strLength = int(strLength / 2) - 1
        start = strLength + 1
    else:
        strLength = int(strLength // 2) - 1
        start = strLength + 2

    # Reverse String half   
    flipString = string[strLength:0:-1] + string[0]
    if flipString == string[start::]:
        return True
    else:
        return False



def longestPalindrome(inputStr):
    inputStrLength = len(inputStr)
    for subStrLength in range(inputStrLength,0,-1):
        maxStart = inputStrLength - subStrLength
        for start in range(0,maxStart+1):
            end = start + (subStrLength)
            if(findPalindrome(inputStr[start:end])):
                return inputStr[start:end]
    return "No Palindromes"


out2 = longestPalindrome("dsfasababad")
print(out2)    
