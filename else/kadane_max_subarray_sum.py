def kadane(a):
    """
    kadane to calculate largest subarry sum
    """
    kad, max_kad = 0, float('-inf')
    curS = 0
    for e in a:
        kad = max(kad + e, e)  # here we start again if we find another better value
        max_kad = max(max_kad, kad)
    return max_kad


t = [1,2,-4,7,1, -29,33, 64]

print(kadane(t))
