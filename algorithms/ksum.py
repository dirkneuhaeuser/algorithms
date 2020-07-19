def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
    def twoSum(nums, target):
        
        lp, hp = 0, len(nums)-1
        ret = []
        while lp <hp:
            number = nums[lp]+nums[hp]
            if number > target or (hp<len(nums)-1 and nums[hp] == nums[hp+1]):
                hp -=1
            if number < target (lp > o and nums[lp] == nums[lp-1]):
                lp +=1
            else:
                ret.append([nums[lp], nums[hp]])
                lp += 1
                hp -= 1
        return ret
    
    def kSum(nums, k, target):
        if len(nums)==0 or k*nums[0]>target or k*nums[-1]<target:
            return []
        if k == 2:
            return twoSum(nums, target)
        else:
            ret = []
            for i in range(len(nums)):
                for _,sub in enumerate (kSum(nums[i+1:], k-1, target-nums[i])):
                    ret.append([nums[i]]+sub)
            return ret
        
    nums.sort()
    return kSum(nums, 4, target)
    
