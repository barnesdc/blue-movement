def longest_pal(str):
    max_length = 1
    string_length  = len(str)
    first_letter = 0
    low = 0
    high = 0
    for i in range(1, string_length):
        low = i-1
        high = i
        # max length for even numbered string
        while low >= 0 and high < string_length and str[low] == str[high]:
            if high - low + 1 > max_length:
                first_letter = low
                max_length = high - low + 1
            low -= 1
            high += 1
        low = i-1
        high = i + 1
        #max length for odd numbered string
        while low >= 0 and high < string_length and str[low] == str[high]:
            if high - low + 1> max_length:
                first_letter = low
                max_length = high - low + 1
            low -= 1
            high += 1
    return str[first_letter: first_letter + max_length]

str = 'hiracecarhi'
print(longest_pal(str))


from itertools import permutations

def all_permutation(str):
    every_permutation = permutations(str)
    for p in list(every_permutation):
        print(''.join(p))

str = 'hello'
all_permutation(str)