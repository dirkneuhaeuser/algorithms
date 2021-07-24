class Solution:
    def numberOfSubstringsSlidingWindow(self, s):
        '''
        Sliding Window..very strange: 
        leftPointer only follows if window complete
        then for eacht step of right pointer add leftpointer
        '''
        count = {c:0 for c in 'abc'}
        i, j = 0, 0
        ret = 0
        while i<len(s):
            count[s[i]] +=1
            while all(count.values()):
                count[s[j]]-=1
                j += 1
            ret +=j # j := substrings wich contain abc but start at different index up to i
            i +=1
        return ret
    
    def numberOfSubstrings(self, s):
        res, last = 0, [-1] * 3
        for i, c in enumerate(s):
            last[ord(c) - 97] = i
            res += 1 + min(last)
        return res
