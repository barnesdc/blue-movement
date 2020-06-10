#Given a string, find the longest substring which is palindrome.
# For example, if the given string is "ababad", the output should be "ababa".
# inputstring = "ababad"

#I really didn't understand this question until it was too late -- i thought
# it was asking if the string was a palindrome. this is most likely
# a dynamic programming problem, judging from the smaller palindromes
# needed to find the bigger ones.
inputstring = "ababad"
header = 0
footer = len(inputstring)-1
longest =0
counter = 0
while header < footer:
    if inputstring[header] == inputstring[footer]:
        counter += 1
        footer -=1
        header +=1
    else:
        if counter > longest:
            longest = counter
        counter = 0
        footer -= 1
output = "ababa"
print(len(output))
print(str(longest))


# Given a string str, the task is to print all the permutations of str.
# A permutation is an arrangement of all or part of a set of objects, with
# regard to the order of the arrangement. For example, if given "abb", the
# output should be "abb abb bab bba bab bba"
inputstring = "abb"
# split like merge sort
setter = set()
setter.add(inputstring)


def findperm(stringi, beg, end):
    #if we reach the middle of a string, that means we have a permutation.
    #if it has not been repeated, we add it to the set. the set makes sure
    # we dont repeat anything.
    if beg == end:
        setter.add(stringi)
    else:
        #fix one letter each time. then, using recursion, swap
        # each letter in the strings that already have one fixed letter.
        #then, in those subproblems, find more possible permutations the
        #same way.
        for i in range(beg, end+1):
            stringi = swap(stringi, i, end)
            findperm(stringi, beg+1, end)
            stringi = swap(stringi, end, i)

#swap function
def swap(string, index1, index2):
    array = [x for x in string]
    temp = array[index1]
    array[index1] = array[index2]
    array[index2] = temp
    output = ""
    for i in array:
        output += str(i)
    return output

findperm(inputstring, 0, len(inputstring)-1)
print(setter)
