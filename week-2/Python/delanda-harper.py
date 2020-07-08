#Given the string, user input.
dh=input()
#Reverse the given string to detect a palindrome as a whole or within the string.
def reverse(dh):
  if len(dh) == 0:
    return dh
  else:
    return reverse(dh[1:])+ dh[0]
print (reverse(dh))
#Compare orginial string with reverse.
if dh == reverse(dh):
  print ("True. This is a palindrome.")
else:
  print("False. This is not a palindrome")
  # After the last else statement instead of having print false, I wanted to include a function that will look at the new reverse string character by character to determine the longest substring in the palindrome. 
def substring(dh):
#maxlen is the size of the substring.  
  maxlen = 1
  start = 0 
  length = len(dh)
  low = 0
  high = 0 
  for i in xrange(1,length):
    low = i - 1
    high = i 
    while low >= 0 and high < length and string[low] == string[high]:
      if high - low + 1 > maxlen:
        print("The value of low and high for" + i + "is low=" + low + "and high=" + high)
        start = low 
        maxlen = high - low + 1
      low -= 1
      high += 1
# This represents strings with an odd length.
    low = i - 1
    high = i + 1 
    while low >= 0 and high < length and string[low] == string[high]:
      if high - low + 1 > maxlen:
        start = low 
        maxlen = high - low + 1
      low -= 1
      high += 1