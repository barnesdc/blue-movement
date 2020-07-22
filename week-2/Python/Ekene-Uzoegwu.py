def longestPalindrome(s):
        
        # Return if string is empty
        if not s: return s

        result = ""
        for i in range(len(s)):
            j = i + 1
            
            while j <= len(s) and len(result) <= len(s[i:]):
            
                if s[i:j] == s[i:j][::-1] and len(s[i:j]) > len(result):
                    result = s[i:j]
                j += 1

        return result

l = "ababad"
print(longestPalindrome(l))

print("\n")


## String permuation


def permutate(str_, Perm_string = ''):
    if len(str_) == 0:
        print(Perm_string)
    else:
        for i in range(len(str_)):
            y = str_[0:i] + str_[i+1:]
            permutate(y, Perm_string + str_[i])

print("abb: permuates to ") 
permutate('abb')

