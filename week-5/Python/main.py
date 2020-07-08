def isBalanced(brackets):
    brackGroupings = [('(',')'), ('[',']'), ('{','}')]
    brackCnt = 0
    brackStack = []
    for bracket in brackets:
        if bracket in {'(', '[', '{'}:
            brackCnt += 1
            ## Add a grouping index to the bracket type stack
            for i, brackGroup in enumerate(brackGroupings):
                if bracket == brackGroup[0]:
                    brackStack.append(i)
        elif bracket in {')', ']', '}'}:
            brackCnt += -1
            ## Check if popping the grouping index off the bracket type stack is the right type
            for i, brackGroup in enumerate(brackGroupings):
                if bracket == brackGroup[1]:
                    ## Some inputs will make it such that we try tp pop fron an empty stack, lets catch any potential errors here
                    try:
                        if brackStack.pop() != i:
                            return 'NO'
                    except:
                        return 'NO'
    if brackCnt == 0:
        return 'YES'
    else:
        return 'NO'

print(isBalanced('[{]}]'))

