def longestPalindromicSubstring(s):
    dp = [[False for i in range(len(s))] for i in range(len(s))]
    for i in range(len(s)):
        dp[i][i] = True
    max_length = 1
    start = 0
    for l in range(2, len(s) + 1):
        for i in range(len(s) - l + 1):
            end = i + l
            if l == 2:
                if s[i] == s[end - 1]:
                    dp[i][end - 1] = True
                    max_length = l
                    start = i
            else:
                if s[i] == s[end - 1] and dp[i + 1][end - 2]:
                    dp[i][end - 1] = True
                    max_length = l
                    start = i
    return s[start:start + max_length]


print(longestPalindromicSubstring("ababa"))


def permutations(string, step=0):
    if step == len(string):
        print("".join(string))

    for i in range(step, len(string)):
        string_copy = [c for c in string]
        string_copy[step], string_copy[i] = string_copy[i], string_copy[step]
        permutations(string_copy, step + 1)


print(permutations('abb'))

# C:\Users\olawa\AppData\Local\Programs\Python\Python38-32
