class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        unique = list(count.keys())
        
        def partition(left, right):
            """
            sorts the unique - key array s.t. all elements with less freq than pivot are left and higher freq are right
            """
            pivot_i = random.randint(left, right)
            pivot_freq = count[unique[pivot_i]]
            lp = left
            unique[right], unique[pivot_i] = unique[pivot_i], unique[right]
            for i in range(left, right):
                if count[unique[i]]<pivot_freq:
                    unique[i], unique[lp] = unique[lp], unique[i]
                    lp += 1
            unique[lp], unique[right] = unique[right], unique[lp]
            return lp 
        

        
        def quickselect(left, right, kth_smallest):
            """
            Auswahlproblem finds the k-th smallest / biggest element(s)
            """
            if left == right: 
                 return
            pivot_i = partition(left, right) 
            if pivot_i == kth_smallest:
                return
            elif pivot_i < kth_smallest:
                quickselect(pivot_i + 1, right, kth_smallest)
            elif pivot_i > kth_smallest:
                quickselect(left, pivot_i - 1, kth_smallest)
        
        quickselect(0, len(unique) - 1, len(unique) - k)
        return unique[len(unique) - k:]
        
