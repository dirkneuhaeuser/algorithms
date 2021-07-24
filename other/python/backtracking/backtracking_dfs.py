def selectStock(saving, currentValue, futureValue):
    '''
    dfs use backtrack to traversal. Here we don't really need to backtrack/undo anythin since the  adjustment is local for the next function only. However, the way of constructing the solution IS BACKTRACKING
    '''
    maxRet = 0
    roi = [x-y for (x,y) in zip(futureValue,currentValue)]
    n = len(currentValue)

    def dfs(temp=0,i=0,saving=saving):
        if i == n:
            nonlocal maxRet
            maxRet = max(temp, maxRet)
            return
        if roi[i]>= 0 and saving>=currentValue[i]:
            dfs(temp + roi[i], i +1, saving -currentValue[i] )
            dfs(temp, i +1, saving)
        else:
            dfs(temp, i +1, saving)

    
    dfs()
    print(maxRet)
    return maxRet

selectStock(250,[175, 133, 109, 210,97], [200, 125, 128, 228, 133])


