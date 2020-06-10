def longestPalindrome(s):
    longest = ""

    for i in range(len(s)):
        ith = extend(i, i, s)
        i_plus_one = extend(i, i + 1, s)
        longest = max(longest, ith, i_plus_one, key=len)

    return longest


def extend(start, end, s):
    while start >= 0 and end < len(s) and s[start] == s[end]:
        start -= 1
        end += 1

    return s[start + 1: end]
