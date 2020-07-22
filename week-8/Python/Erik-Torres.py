#Stone's Love

def bin_search_special(arr, ele):
    l=0
    h=len(arr)-1
    while l<=h:
        m = (l+h)//2
        if ele==arr[m]:
            return m
        elif arr[m]>ele:
            h = m-1
        else:
            l = m+1
    return l

n,q = map(int, input().split())
a = list(map(int, input().split()))
s=0
for i in range(len(a)):
    s+=a[i]
    a[i]=s
m = list(map(int, input().split()))
for i in m:
    print(bin_search_special(a, i)+1)

#Repeated K Times
max_val = 100001

def search(ar, N, K):
    result = max_val + 1
    for i in range(0, N):
        count = 1

        for j in range(i + 1, N):
            if (ar[i] == ar[j]):

                count += 1

        if (count == K):
            result = min(result, ar[i])

    return result


N = int(input())
ar = list(map(int, input().split()))

K = int(input())
print(search(ar, N, K))