class Solution:
    def uniquePathsWithObstacles2(self, obstacleGrid: List[List[int]]) -> int:
        '''
        Tabulation:
        '''        
        if obstacleGrid[-1][-1]==1:
            return 0
        dp = [[0 for _ in range(len(obstacleGrid[0]))] for _ in range(len(obstacleGrid))]
        dp[-1][-1] = 1
        for i in range(len(obstacleGrid)-1, -1, -1):
            for j in range(len(obstacleGrid[0])-1,-1,-1):
                if i == len(obstacleGrid)-1 and j==len(obstacleGrid[0])-1:
                    continue
                if obstacleGrid[i][j]==1:
                    dp[i][j]=0
                    continue
                num = 0
                if i+1 < len(obstacleGrid):
                    num+=dp[i+1][j]
                if j+1 < len(obstacleGrid[0]):
                    num+=dp[i][j+1]
                dp[i][j] = num
        return dp[0][0]
    
    
    
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        '''
        Memoization:
        '''
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])

        
        @lru_cache(None)
        def memo(x,y):
            if x>=n or y>= m or obstacleGrid[x][y]==1:
                return 0
            if x==n-1 and y==m-1:
                return 1
            num = 0
            if x<n:
                num += memo(x+1, y)
            if y<m:
                num += memo(x, y+1)
            return num
        
        if n<=0 or obstacleGrid[0][0]==1:
            return 0
        else:
            return memo(0,0)
                
        
    
        
        
