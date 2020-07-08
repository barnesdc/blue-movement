# Prompt 1

# is_pal is a helper function that checks if a string is a
# palindrome.


def is_pal(string):
    back = -1
    for i in range(0, len(string) // 2):
        if string[i] != string[back]:
            return False
        back -= 1
    return True


# max_pal is a helper function that finds the longest
# palindrome string in an array of palindromes.


def max_pal(word_list):
    max_val = -999
    maximum = ""
    for i in word_list:
        if len(i) > max_val:
            max_val = len(i)
            maximum = i
    return maximum


# long_pal is the main function that uses is_pal to check if the
# different substrings in the given string are palindromes. If the
# string is a palindrome, the substring is pushed onto an array of
# palindromes. After obtaining an array of substring palindromes,
# the max_pal function is used to find the longest substring
# palindrome in the array of substring palindromes.


def long_pal(string):
    words = []
    for i in range(0, len(string) + 1):
        for j in range(i + 1, len(string) + 1):
            if is_pal(string[i:j]):
                if string[i:j] != "":
                    words.append(string[i:j])

    return max_pal(words)


# Prompt 2
# The remove function uses a string and index value to remove the
# letter at the position of the index value given.
def remove(s, idx):
    s = s[:idx] + s[idx + 1:]
    return s


def all_perms(string):
    perms = []
    word = ""

    # Checks if the string is empty or if there is only one letter in
    # the string, in which case, the string is returned.

    if len(string) <= 1:
        return string

    else:

        # Creates a string called "word" using the remove function.
        for i in range(len(string)):
            word = remove(string, i)
            # Appends a new string to the perms array.
            for perm in all_perms(word):
                perms.append(string[i] + perm)
        return perms


if __name__ == "__main__":
    print(long_pal("ababad"))
    print(long_pal("a"))
    print(long_pal("ab"))
    print(long_pal("aba"))
    print(long_pal("hannah"))
    
    print(all_perms("abb"))
