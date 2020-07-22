def finalPrice(prices):
    # create and assign empty_list as an empty
    empty_List = []
    size = len(prices)
    for i in range(size -1):
        # here we slice from index 1 of price list to find the minimu(since index 0 and 1 are static)
        # assign k to min of price from index 1
        k = min(prices[i+1:])
        if(prices[i] >= k):
            empty_List.append(prices[i] - k)
        else:
            empty_List.append(prices[i])
    empty_List.append(prices[size -1])
    print(sum(empty_List))
    for i in range(size):
        if prices[i] == empty_List[i]:
            print(i,end= ' ')


x = int(input("enter text"))
print()
read_input = []
for num in range(0, x):
    ele = int(input())
    read_input.append(ele)

print("Results here:")
prices = read_input[::]
finalPrice(prices)
