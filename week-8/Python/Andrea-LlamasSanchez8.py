# -*- coding: utf-8 -*-
"""
Created on Wed Jul 22 02:18:30 2020

@author: andre
"""
from collections import Counter

def search(list_picked, searching_for, left, right, lowest):
    if right >= left:
        center_index = left + (right - left)//2
        
        if list_picked[center_index] >= searching_for:
            if center_index < lowest:
                lowest = center_index
            return search(list_picked, searching_for, left, center_index - 1, lowest)
        
        else:
            return search(list_picked, searching_for, center_index + 1, right, lowest)
            
    else:
        return lowest
        

def query_days(num_days, num_queries, list_picked, list_queries):
    sum_so_far = 0
    day_sums = []
    for item in list_picked:
        sum_so_far += item
        day_sums.append(sum_so_far)
    return_list = []
    for query in list_queries:
        return_list.append(search(day_sums, query, 0, len(list_picked) - 1, len(day_sums)))
    print(return_list)
    return return_list

query_days(5, 4, [1, 2, 3, 4, 5], [3, 8, 10, 14])

def repeated_k_times(num_list, k):
    vals_dict = Counter(num_list)
    valid_keys = []
    for key in vals_dict:
        if vals_dict[key] == k:
            valid_keys.append(key)
    return min(valid_keys)

print(repeated_k_times([2, 2, 1, 3, 1], 2))
