
# Find Palindrome finds

def findPalindrome(string):
    # even or odd number of characters?
    strLength = len(string)
    if (strLength % 2) == 0:
        strLength = int(strLength / 2) - 1
    else:
        strLength = int(strLength // 2) - 1
    # Reverse String half   
    flipString = string[strLength:0:-1] + string[0]

    if flipString in string:
        return True
    else:
        return False



out = findPalindrome("ababa")
print(out)