class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        
        ret = "".join(sorted([str(num) for num in nums], key=LargerNumKey, reverse=True))
        return ret if ret[0] != "0" else "0"
        
        
class LargerNumKey(str):
    def __lt__(a, b):
        return a + b < b + a
        
