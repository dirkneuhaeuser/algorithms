def numOfSubarrays(self, arr: List[int]) -> int:
    '''
    Nice solution, using prefix sums for sum of subarrays. ALWAYS when you deal with sum of subarrays -> convert it to prefix-sum
    '''
    
    prefix_sum = [0]
    for a in arr:
        prefix_sum.append(prefix_sum[-1]+a)
            
    
        
    # The O(n^2) main Idea -> TimeLimit exceeded
    # calc all poss i<j where p[i] != P[j] (mod 2) -> O(n^2) will not pass
    
    # Better for a given j, rembember how many were even or odd
    
    ans= odd = even = 0
    for psum in prefix_sum:
        if psum & 1 == 1:
            ans += even
            odd += 1
        else:
            ans += odd
            even +=1
    return ans  % (10**9 +7)


def numOfSubarrays2(self, arr: List[int]) -> int:
    '''
    The straight forward approach (simulating more or less):
    '''
    even, odd = 0, 0
    ret = 0
    for i in range(len(arr)):
        if arr[i]%2 == 1:
            odd,even = even+1, odd
        else:
            odd, even = odd, even+1
        ret += odd
    return ret % (10**9 +7)
