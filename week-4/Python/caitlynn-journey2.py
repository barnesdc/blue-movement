arr = [ int(x) for x in input().split(' ') ]
k = input()
max = 1000001
def find_minmax(arr, k):
    result = MAX + 1
    for i in range(0, len(k)):  
        if (arr[i] > 0): 
            count = 1
            for j in range(i + 1, n): 
                if (arr[i] == arr[j]): 
                    count += 1
            if (count == k): 
                res = min(res, arr[i]) 
                
                return res
    print(res)
for number in arr:
    res = find_minmax(arr, n, k)
    print(res)