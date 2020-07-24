# question one


from collections import Counter


def q1(a, x):
    l = 0
    r = len(a) - 1

    while l < r:
        m = l + (r - 1) // 2
        if a[m] >= x:
            r = m
        else:
            l = m + 1
    return l + 1

############ END QUESTION ONE ##############


# question two


def q2(i, k):
    c = Counter(i)
    hm = dict(c)
    l = []
    for key, v in hm.items():
        if v == k:
            l.append(key)
    return min(l)


print(q2([1, 2, 2, 3, 4], 2))
