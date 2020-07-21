#solution 2
n=int(input())
arr=list(map(int,input().split()))
arr.sort()
k=int(input())
# s=set(arr)
sol_n=[0]*len(arr)
for i in arr:
    sol_n[i]=+sol_n[i]+1
    if sol_n[i]==k:
            print(i)
            break

#solution 1
from bisect import bisect_left as bleft
from itertools import accumulate as accm
 
n,q=map(int,input().split())

num_stones=list(map(int,input().split()))
summed=list(accm(num_stones))
 
queries=list(map(int,input().split()))[:q]
 
for i in queries: print(bleft(summed,i)+1)
