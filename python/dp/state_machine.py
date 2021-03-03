def maxProfit(self, prices: List[int]) -> int:
    '''
    state_machines
    '''
    if len(prices)==0: return 0
    s1 = - prices[0]
    s2 = 0
    s3 = [0,0]
    for p in prices:
        s1 = max(s1, s3[1]-p)
        s2 = max(s2, s1+p)
        s3 = [s2, s3[0]]       
    return s2
