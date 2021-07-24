class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        '''
        Cutting a stick into len(cuts) pieces -> return min cuts
        '''
        cuts.extend([0, n])  # add 2 fake cuts as the boundary of the first cut
        cuts.sort()
        
        @lru_cache(None)
        def f(i, j):
            if i + 1 >= j: return 0
            return cuts[j] - cuts[i] + min((f(i, k) + f(k, j) for k in range(i+1, j)), default=0)  # go through all the cuts as the first cut
        return f(0, len(cuts)-1)
    
    
    
    def minCost2(self, n: int, cuts: List[int]) -> int:
        '''
        dp[i][j] means the min price of cutting all edges between i and j
        '''
        cuts.extend([0, n])  # add 2 fake cuts as the boundary of the first cut
        cuts.sort()
        dp = [[0 for _ in range(len(cuts))] for _ in range(len(cuts))]
        for i in range(len(cuts)-1,-1,-1):
            for j in range(i+1, len(cuts)):
                if i+1<j:
                    dp[i][j]=dp[i][i+1]+dp[i+1][j]
                    for k in range(i+2, j):
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j])
                
                dp[i][j] += cuts[j]-cuts[i]
        
        return dp[0][len(cuts)-1]-n
