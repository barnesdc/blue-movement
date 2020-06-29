#Problem 1
 # The function to find logest pallindrome substring

def findLongPalsubstr(my_str):
#Initialize the variables
   max_len = 1
   start_point = 0
   str_len = len(my_str)
   low = 0
   high = 0
#for loop to loop through the ztring no matter how long it may be
 
   for i in range(1, str_len):
       low = i - 1
       high = i
       while (low >= 0 and high < str_len and my_str[low] == my_str[high]):
           if (high - low + 1 > max_len):
               start_point = low
               max_len = high - low + 1
#Subtracts/adds a value from the variable and assigns the result to that variable.
           low -= 1
           high += 1
       low = i - 1
       high = i + 1
       while (low >= 0 and high < str_len and my_str[low] == my_str[high]):
           if( high - low + 1 > max_len):
               start_point = low
               max_len = high - low + 1
           low -= 1
           high += 1
   # returning the result
   return my_str[start_point:start_point + max_len]
# driver code for testing
# input string
my_str = "ababad"
# printing the result
print(findLongPalsubstr(my_str))
         
