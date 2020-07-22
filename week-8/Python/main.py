def stoneCounter(inp):
    ## Parse n and q list lengths
    nLen, inp = int(inp[:inp.index(' ')]), inp[inp.index(' ')+1:]
    qLen, inp = int(inp[:inp.index(' ')]), inp[inp.index(' ')+1:]
    ## Parse n and q lists
    nqList = [int(nqItem) for nqItem in inp.split(' ')]
    n = nqList[:nLen]
    q = nqList[nLen:]
    
    ## We create a list of how many stones we have at each day
    stonesPerDay = [n[0]]
    for numStones in n[1:]:
        stonesPerDay.append(numStones + stonesPerDay[-1])
    
    ## Find on which day the query is from using np's searchsorted
    import numpy as np
    queryAnswer = [n[np.searchsorted(stonesPerDay, qItem)] for qItem in q]
    print(queryAnswer)
    
    
def strToList(s):
    return [int(sItem) for sItem in s.split(' ')]
    
def listToStr(l):
    return ' '.join([str(lItem) for lItem in l])
    
n = [1, 2, 3, 4, 5]
q = [3, 8, 10, 14]

input = f'{len(n)} {len(q)} {listToStr(n)} {listToStr(q)}'

stoneCounter(input)