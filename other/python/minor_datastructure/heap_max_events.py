class Solution:
    def maxEvents(self, A):
        A.sort(reverse=True)
        heap = []
        ret = 0
        while heap or A:
            if not heap: d = A[-1][0] 
            while A and A[-1][0] <=d:
                heapq.heappush(heap, A.pop()[1])
            
            heapq.heappop(heap)
            d +=1
            ret +=1
            
            while heap and heap[0]<d:
                heapq.heappop(heap)
        
        return ret
    
