#!/usr/bin/env python3

d = {1:3, 2:2, 3:3, 4:2}
l = [k for k in d if d[k]==2]

def findRepeat(n, arr, k):
    count_dict = dict()


    for i in range(n):
        key = arr[i]
        if key not in count_dict:
            count_dict[key] = 1
        else:
            count_dict[key] += 1

    l = [key for key in count_dict if count_dict[key]==k]
    print(min(l))

def stones(arr, n, q):
    l = 0
    r = n - 1

    if sum(arr) == q:
        return n

    while l < r:
        m = (l + r) // 2
        Sum = sum(arr[:m+1])

        if Sum >= q:
            r = m
        else:
            l = m + 1

    return l+1

arr = [2,2,1,3,1]
arr2 = [1,2,3,4,5]
queries = [3,8,10,14]

findRepeat(len(arr),arr,2)
print()

for i in queries:
    L = stones(arr2, len(arr2), i)
    print(L)
