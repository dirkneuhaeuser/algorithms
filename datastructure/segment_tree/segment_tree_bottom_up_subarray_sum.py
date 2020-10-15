class NumArray:
    '''
    Segment tree: concrete and classy binary tree. at leaves save the array and each parent saves the sum of its two children
    '''
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.tree = [0]*(self.n*2)
        j = 0
        for i in range(self.n, len(self.tree)):
            self.tree[i] = nums[j]
            j+=1
        for i in range(self.n-1, 0, -1):
            self.tree[i] = self.tree[2*i] + self.tree[2*i+1]
        
    def update(self, pos: int, val: int) -> None:
        pos += self.n
        self.tree[pos] = val
        while (pos > 0):
            if pos % 2:
                pos -= 1
            
            self.tree[pos//2] = self.tree[pos] + self.tree[pos+1]
            pos //= 2

    def sumRange(self, i: int, j: int) -> int:
        i += self.n
        j += self.n
        ret = 0
        while i<=j:
            if i%2==1:
                ret += self.tree[i]
                i +=1
            if j%2==0:
                ret += self.tree[j]
                j -= 1
            
            i //= 2
            j //= 2
        
        return ret
