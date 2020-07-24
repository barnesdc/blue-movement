# Prompt 1: Given a string, find the longest substring which is palindrome. 
# For example, if the given string is "ababad", the output should be "ababa".

def longest_substring(str):
    # used lists since strings are immutable in Python
    substring_arr = []
    len_str = len(str)
    counter = 0
    max = 0
    for i in range(len_str):
        for j in range(len_str - i + 1):
            if (checkPalindrone(str[i:i+j], str)): 
                counter += 1
                if counter > max:
                    max = counter
                    substring_arr.clear()
                    substring_arr.append(str[i:i+j])
        counter = 0
    result = ''.join(substring_arr)
    return result

def checkPalindrone(sub_s, str2):
    start = 0
    end = len(sub_s)-1
    sub_sList = list(sub_s)
    while end > start:
        sub_sList[start], sub_sList[end] = sub_sList[end], sub_sList[start]
        start += 1
        end -= 1
    strng = ''.join(sub_sList)
    
    # Under the assumption that a single letter is a palindrone
    if strng == sub_s and len(sub_s) > 1:
        return True
    elif len(str2) == 1:
        return True
    else:
        return False


print(longest_substring("ababad"))
print(longest_substring("aba"))
print(longest_substring("dancer"))
print(longest_substring(""))
print(longest_substring("a"))

# Prompt 2: Given a string str, the task is to print all the permutations of str.
# A permutation is an arrangement of all or part of a set of objects, with regard 
# to the order of the arrangement. For example, if given "abb", the output should 
# be "abb abb bab bba bab bba"

def findPermutations(str, step = 0):

    # base case (print result if no more recursions are needed)
    if step == len(str):
        print("".join(str))

    for i in range(step, len(str)):

        # array makes manipulation of the given string easier
        str_perm = [character for character in str]
        str_perm[step], str_perm[i] = str_perm[i], str_perm[step]
        findPermutations(str_perm, step + 1)

print(findPermutations("abb"))
print(findPermutations("a"))
print(findPermutations(""))
print(findPermutations("cat"))


