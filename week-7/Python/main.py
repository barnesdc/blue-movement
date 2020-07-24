#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'partitionArray' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY numbers
#
from itertools import combinations

## Here we generate all sublists
def getSublists(numbers):
    sublists = [
        numbers[i:j]
        for i in range(0, len(numbers) + 1)
        for j in range(i + 1, len(numbers) + 1)
    ]
    return sublists


def partitionArray(k, numbers):
    import itertools

    sublists = getSublists(numbers)

    lenKSublists = [sublist for sublist in sublists if len(sublist) == k]
    for numLists in range(0, len(lenKSublists) + 1):
        for combination in itertools.combinations(lenKSublists, numLists):
            areEqual = True
            for num in numbers:
                if num in combination:
                    combination = combination.remove(num)
                else:
                    areEqual = False
                    break
            if areEqual == True:
                return "Yes"
    return "No"


#
# Complete the 'totalTriplets' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY capacity
#  2. LONG_INTEGER desiredCapacity
#


def totalTriplets(capacity, desiredCapacity):
    numWorkers = len(capacity)
    ## We will iterate over the list in pairs and pick the third triplet randomly from the remainder of the list
    numValidTriplets = 0
    ## This makes sure we don't accidentally add the same triplet twice
    knownTrips = []

    ## Create a dictionary of the capacities and their indices w/ dict comp
    capacityDict = {cap: capInd for capInd, cap in enumerate(capacity)}

    ## First lets iterate over the workers and retreive all adjacent worker paris
    for capInd in range(numWorkers - 1):
        adjWorkers = (capacity[capInd], capacity[capInd + 1])
        ## Then find their work value
        workVal = adjWorkers[0] * adjWorkers[1]

        ## If the current workVal is zero, then any value but zero is not achievable
        if workVal == 0:
            if desiredCapacity != 0:
                continue
            target = 0
        ## If not then we can get the target by default
        else:
            target = desiredCapacity / workVal

        ## We say a triplet exists if the set of triplet indices has never been seen before
        if target in capacityDict and capacityDict[target] not in {capInd, capInd + 1}:
            triplet = set([capInd, capInd + 1, capacityDict[target]])
            if triplet not in knownTrips:
                knownTrips.append(triplet)
                numValidTriplets += 1
    return numValidTriplets

