class NumArray:
    def __init__(self, nums: List[int]):
        '''
        Binary indexed tree / Fenwick tree for calculating sum of subarrays where elements may change
        1-indexed based
        tree as array saves sum
        update and sum operations work in o(log(n))
        '''
        self.n = len(nums)
        self.tree = [0]*(len(nums)+1)
        self.arr = [0]*len(nums)
        for i in range(len(nums)):
            self.update(i, nums[i])


    def update(self, i: int, val: int) -> None:
        i += 1
        inc = val - self.arr[i-1]
        self.arr[i-1] += inc
        while i < self.n+1:
            self.tree[i] += inc #tree is 0 indexed-based
            i += i&-i # adding 1&-1 gets the next right node


    def sumRange(self, i: int, j: int) -> int:
        pass
        j += 1
        sumj = 0
        sumi = 0
        while j>=1:
            sumj += self.tree[j]
            j -= j&-j # subtracting j&-j gets the parent of j
        
        while i>=1:
            sumi += self.tree[i]
            i -= i&-i
        
        return sumj-sumi
        
