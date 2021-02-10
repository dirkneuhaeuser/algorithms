class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        """
        # dp[i][j] saves the maximum of points, you can get of the sequence i to j
        i and j are not inclusive ( you can only burst i+1, .. j-1)

        """
        
        nums = [1] + nums + [1]
        dp = [[0 for _ in range(len(nums))] for _ in range(len(nums))]
        
        
        # basecases: 
        # i + 1 <= j: 0
        
        # recursion
        # dp[i][j] = max([ nums[k-1] * nums[k] * nums[k+1] = dp[i][k] + dp[k][j] for k in range(i+1, j)]
        for i in range(len(nums)-2,-1,-1):
            for j in range(i+2, len(nums)):
                # pretent that baloon i is the only one left in the sequence:
                # balloons between i and k (dp[i][k]) and k and j (dp[k][j]) are already busted:
                dp[i][j] = max([ nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j] for k in range(i+1, j)])
        
        return dp[0][-1]
