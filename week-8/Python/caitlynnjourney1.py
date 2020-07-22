counts = [ int(x) for x in input().split(' ') ]
stones = [ int(x) for x in input().split(' ') ]
queries = [ int(x) for x in input().split(' ') ]

#Prompt 1:
def find_day(query):
    total_stones = 0
    for stone in stones:
        total_stones += stone
        if total_stones >= query:
            current_days = stones.index(stone) + 1
            return current_days

for query in queries:
   current_days = find_day(query)
   print(current_days)



# Prompt 2:
# arr = [ int(x) for x in input().split(' ') ]
# k = input()
# MAX = 1000001
# def find_minmax(arr, k):
#     result = MAX + 1
#     for i in range(0, len(k)):  
#         if (arr[i] > 0): 
#             count = 1
#             for j in range(i + 1, n): 
#                 if (arr[i] == arr[j]): 
#                     count += 1
#             if (count == k): 
#                 result = min(result, arr[i])
#                 return result
#     print(res)
# for number in arr:
#     result = find_minmax(arr, k)
#     print(find_minmax(arr, k))