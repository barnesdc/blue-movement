
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
    else:
        strLength = int(strLength // 2) - 1
    # Reverse String half   
    flipString = string[strLength:0:-1] + string[0] 
    if flipString == string[0:strLength+1]:
        return True
    else:
        return False

def longestPalindrome(inputStr):
    # Check full string
    if findPalindrome(inputStr):
        print(findPalindrome)
        return inputStr
    else:
        subStrLength = len(inputStr) - 1
        for i in range(subStrLength,2,-1):
            for j in range(0,i):
                end = j + i
                if findPalindrome(inputStr[j:end]):
                    return inputStr[j:end]
        return "no Palindromes"

out1 = findPalindrome("abadad")
out2 = longestPalindrome("asabad")
print(out1)
print(out2)    
