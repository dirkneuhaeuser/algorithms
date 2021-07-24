class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        """
        LC: 164
        Bucket sort to find max Gap
        
        idea: the size of each bucket is the minimal distance. -> 
        You only need to check the biggest element of the current bucket with the smallest of the proceeding bucket
        """
        
        if len(nums) < 2:
            return 0
        a, b = min(nums), max(nums)
        if a == b:
            return 0
        size = (b - a) // (len(nums) - 1) or 1

        buckets = [[None, None] for _ in range((b-a) // size + 1)]
        
        for n in nums:
            b = buckets[(n-a) // size]
            b[0] = n if b[0] is None else min(b[0], n)
            b[1] = n if b[1] is None else max(b[1], n)
        
        buckets = [b for b in buckets if b[0] is not None]
        return max(buckets[i][0] - buckets[i-1][1] for i in range(1, len(buckets)))
        
