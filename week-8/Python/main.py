from bisect import bisect_left as bisect_left
from itertools import accumulate as accumulate



days_and_querries = input()
stones = input()
querries = input()



n, q = days_and_querries.split()
stones_list = map(int,stones.split())
querries_list = map(int,querries.split())
stones_sum = list(accumulate(stones_list))



for i in querries_list: 
count = bisect_left(stones_sum,i)+1
print(count) 
