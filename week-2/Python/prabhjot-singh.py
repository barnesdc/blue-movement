
from itertools import permutations

# Given a string, find the longest substring which is palindrome. 
# For example, if the given string is "ababad", the output should be "ababa".
def longestPalindromeSubstring(string):
  if type(string) is not str:
    return TypeError('Argument given must of type str')

  longest = ''

  # O(n^3), n = length of string
  for i in range(0, len(string) + 1):
    for j in range (1, len(string) + 1):
      candidate = string[i:j]
      if len(candidate) > len(longest) and isPalindrome(candidate):
        longest = candidate

  return longest

# Returns true if string is a palindrome
def isPalindrome(string):
  return string == string[::-1]



# Given a string str, the task is to print all the permutations of str. 
# A permutation is an arrangement of all or part of a set of objects, with regard to the order of the arrangement. 
# For example, if given "abb", the output should be "abb abb bab bba bab bba"
def allPermutations(string):
  if type(string) is not str:
    return TypeError('Argument given must of type str')

  # O(n). Easy way using library: https://docs.python.org/3/library/itertools.html#itertools.permutations
  perms = set()
  permsList = list(permutations(string)) # [('a', 'b', 'b'), ('a', 'b', 'b'), ('b', 'a', 'b'), ('b', 'b', 'a'), ('b', 'a', 'b'), ('b', 'b', 'a')]

  for perm in permsList:
    perms.add(''.join(perm))


  # My Way: Recursion. O(n^2 * n!)
  # Basically takes out each element, puts it in front, and combines it with rest of the string
  # if len(string) is 0: return ''        # Base Case
  # if len(string) is 1: return string    # Base Case

  # perms = set()
  # for i in range(len(string)):
  #   leftOverString = string[:i] + string[i + 1:]    # String without the i-th element
  #   for perm in allPermutations(leftOverString):
  #     perms.add(string[i] + perm)


  return perms



# Test Cases
assert(longestPalindromeSubstring('') == '')
assert(longestPalindromeSubstring('a') == 'a')
assert(longestPalindromeSubstring('ababad') == 'ababa')
assert(longestPalindromeSubstring('aaabbd') == 'aaa')
assert(longestPalindromeSubstring('baaaab') == 'baaaab')
assert(longestPalindromeSubstring('abc') == 'a')
assert(longestPalindromeSubstring('caabaad') == 'aabaa')
assert(type(longestPalindromeSubstring(123)) == TypeError)

assert(allPermutations('') == {''})
assert(allPermutations('a') == {'a'})
assert(allPermutations('aaa') == {'aaa'})
assert(allPermutations('ab') == {'ab', 'ba'})
assert(allPermutations('abb') == {'abb', 'abb', 'bab', 'bba', 'bab', 'bba'})
assert(allPermutations('abc') == {'abc', 'acb', 'bac', 'bca', 'cba', 'cab'})
assert(type(allPermutations(123)) == TypeError)


print("All Good!")