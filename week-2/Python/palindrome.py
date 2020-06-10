#Caitlynn Journey
#Submission 6/9/20
#Prompt 1 

def findLongPalsubstr(s):
   max_len = 1
   start_point = 0
   str_len = len(s)
   low = 0
   high = 0
   #the time complexity is O(j)
   for i in range(1, str_len):
       low = i - 1
       high = i
       while (low >= 0 and high < str_len and s[low] == s[high]):
           if (high - low + 1 > max_len):
               start_point = low
               max_len = high - low + 1
           low -= 1
           high += 1
       low = i - 1
       high = i + 1

       ####
       while (low >= 0 and high < str_len and s[low] == s[high]):
           if( high - low + 1 > max_len):
               start_point = low
               max_len = high - low + 1
           low -= 1
           high += 1
   # returning the result
   return s[start_point:start_point + max_len]

#given string 
s = "ababbabaaaccabbbabaaaa"
print(findLongPalsubstr(s))

#Prompt 2
from itertools import permutations
def findPermutations(s):
  s = "ababbabaaaccabbbabaaaa"
  lists = permutations(s)
  for permatation in list(lists):
    print(''.join(permatation))

