#Problem 1

from bisect import bisect_left as bl
from itertools import accumulate as pre
 
n,q=map(int,input().split())
stones=list(map(int,input().split()))
pre_sum=list(pre(stones))
 
queries=list(map(int,input().split()))[:q]
 
for q in queries: print(bl(pre_sum,q)+1) 

#Problem 2

n=int(input())
l=list(map(int,input().split()))
l.sort()
k=int(input())
s=set(l)
ans=[0]*len(l)
for i in l:
    ans[i]=+ans[i]+1
    if ans[i]==k:
            print(i)
            break



