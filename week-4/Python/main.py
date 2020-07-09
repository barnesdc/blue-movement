  
    
    


def finalPrice(prices):
    total, fullyPricedItems = 0, []
    
    for i, price in enumerate(prices):
        j = i+1
        foundLowerPrice = False
        while j < len(prices):
            if prices[j] <= price:
                total += price-prices[j]
                foundLowerPrice = True
                break
            j += 1
        if not foundLowerPrice:
            total += price
            fullyPricedItems += [str(i)]
    
    print(total)
    print(' '.join(fullyPricedItems))
    
    
    
def applyOperations(arr):
    from collections import deque
    d = deque()
    for i, item in enumerate(arr):
        if i%2==1:
            d.appendleft(item)
        else:
            d.append(item)
    if i%2==1:
        return deque(list(d)[::-1])
    return d

l = [1, 3, 2, 4]

print(applyOperations(l))



