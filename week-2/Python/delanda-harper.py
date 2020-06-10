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
  # After the last else statement instead of having print false, I wanted to include a function that will look at the new reverse string character by character to determine the longest substring in the palindrome. However I am stuck. 