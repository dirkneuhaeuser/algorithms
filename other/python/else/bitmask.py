class Solution:
    def longestAwesome(self, s: str) -> int:
        '''
        bit-masks to save status. Here we have a bit-mask of length 10 for number 0 to 9. In each bit we save the information whether to decimal is odd(1) or even(0). In a seen array we save whether we have already encountered that mask -> we can earase the odd numbers
        '''
        cur = 0
        ret = 0
        n = len(s)
        seen = [-1] + [n]*2**10
        for i,e in enumerate(s):
            cur ^= (1 << int(e))
            for j in range(10): 
                ret = max(ret, i - seen[cur ^ (1 << j)]) # ignoring if j was odd -> j becomes 0
            ret = max(ret, i -seen[cur])
            seen[cur] = min(seen[cur],i)
        return ret


    
    def longestAwesome1(self, s: str) -> int:
        left_most_masks = {0:-1}
        valid_masks = {1 << i for i in range(10)} | {0}
        ans = 0
        curr_mask = 0
        for i, x in enumerate(map(int, s)):
            curr_mask ^= 1 << x ## Flips the bit of the i-th bit to indicate whether its odd or even
            for valid_mask in valid_masks:
                left_mask = valid_mask ^ curr_mask # all remaining odd digits remain 1 (apart of the one exception) -> if we seen that: nice we can create a valid substring
                if left_mask in left_most_masks:
                    ans = max(ans, i - left_most_masks[left_mask])
            if curr_mask not in left_most_masks:
                left_most_masks[curr_mask] = i
        return ans
    
