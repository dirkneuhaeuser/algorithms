class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        """
        meet in the middle-algo:
        
        Given a set of n integers where n <= 40, Determine the maximum sum subset (subsequence) having sum less than or equal S (or close to)
        """
        
        def dfs(idx, arr, sums, cur):
            if idx == len(arr):
                sums.add(cur)
                return
            dfs(idx+1, arr, sums, cur + arr[idx])
            dfs(idx+1, arr, sums, cur)
        
        ret = float('inf')
        s1, s2 = set(), set()
        dfs(0, nums[:len(nums)//2],s1, 0)
        dfs(0, nums[len(nums)//2:],s2, 0)
        
        s2 = sorted(s2)
        for s in s1:
            target = goal - s
            idx = bisect_left(s2, target)
            if idx < len(s2):
                ret = min(ret, abs(target - s2[idx]))
            if idx > 0:
                ret = min(ret, abs(target - s2[idx-1]))
        return ret
    
