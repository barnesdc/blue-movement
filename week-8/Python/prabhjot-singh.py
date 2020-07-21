
# Prompt 1: https://i.imgur.com/JTOFAnY.png
# Uses bisect module, passes everything
from bisect import bisect_left
from itertools import accumulate

n, q = map(int, input().split())
nums = list(map(int, input().split()))
accumulatedSum = list(accumulate(nums))

queries = list(map(int, input().split())) [:q] # Up to q (idk why they provide more than q, kinda pointless, tbh)

for query in queries:
    print(bisect_left(accumulatedSum, query) + 1)


# Passes 2 test cases, one timed out
# Modifies normal binary search algorithm
# 
# n_q = input().split()
# n = int(n_q[0])
# q = int(n_q[1])

# nums = [int(i) for i in input().split()]
# queries = [int(i) for i in input().split()]

# accumulatedSum = []
# accSum = 0
# for i in range(n):
#     accSum = accSum + nums[i]
#     accumulatedSum.append(accSum)

# for i in range(q):
#     query = queries[i]
#     low = 0
#     high = n - 1
#     minimum = n - 1

#     while low <= high:
#         mid = (high + low) // 2
#         if accumulatedSum[mid] < query:
#             low = mid + 1
#         elif accumulatedSum[mid] > query:
#             minimum = min(mid, minimum)
#             high = mid - 1
#         else:
#             minimum = min(mid, minimum)
#             break

#     print(minimum + 1)



# Prompt 2: https://i.imgur.com/CfuKZ5p.png
# Conciser version using collections module and a lambda function
from collections import Counter
n = int(input())
nums = list(map(int, input().split()))
k = int(input())
counts = Counter(nums)
print(
        # Returns the smallest num, count tuple
        min(
                # Filters through the items in the counter
                # for counts that match k
                filter(lambda item_freq: item_freq[1] == k, counts.items())
        )
[0]) # Prints the num from the the smallest num, count tuple


# Passes all test cases using item->count dictionary
# item_freq_dict = {}
# for num in nums:
#     try:
#         item_freq_dict[num] += 1
#     except:
#         item_freq_dict[num] = 1

# minNum = float("inf")
# for num, count in item_freq_dict.items():
#     if count == k:
#         minNum = min(minNum, num)
# print(minNum)
