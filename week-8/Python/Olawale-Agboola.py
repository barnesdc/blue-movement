


# CODE 1
from bisect import bisect_left as num1

from itertools import accumulate as prior

N,Q=map(int,input().split(" "))

array = list(map(int, input().split()))

prior_add = list(prior(array))

friend_q = list(map(int, input().split()))

for x in range(Q):
    print(num1(prior_add, friend_q[x]) + 1





# Code 2
import math
N = int(input())

no = [int(x) for x in input().split(' ')]
K = int(input())
re = dict()
for i in no:
    if i not in re:
        re[i] = 1
    else:
        re[i] += 1

answer = math.inf
for j in re:
    if re[j] == k:
        if answer > j:
            answer = j
print(answer)