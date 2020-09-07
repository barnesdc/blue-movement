def Richo_findLong_Palsubstr(_my_str):
   max_len = 1
   _begin_point = 0
   str_len = len(_my_str)
   low = 0
   high = 0
   for i in range(1, str_len):
       low = i - 1
       high = i
       while (low >= 0 and high < str_len and _my_str[low] == _my_str[high]):
           if (high - low + 1 > max_len):
               _begin_point = low
               max_len = high - low + 1
           low -= 1
           high += 1
       low = i - 1
       high = i + 1
       while (low >= 0 and high < str_len and _my_str[low] == _my_str[high]):
           if( high - low + 1 > max_len):
               _begin_point = low
               max_len = high - low + 1
           low -= 1
           high += 1
   #result
   return _my_str[_begin_point:_begin_point + max_len]

# input string
_my_str = "ababad"
print(Richo_findLong_Palsubstr(_my_str))
 
