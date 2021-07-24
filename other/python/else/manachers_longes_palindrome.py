def longestPalindrome(self, s: str) -> str:
    # Manachers Algo, let's go! 
    # https://medium.com/hackernoon/manachers-algorithm-explained-longest-palindromic-substring-22cb27a5e96f
    newS = "#"
    for e in s:
        newS += e+'#'
        
    length = len(newS)
    p = [0]*length
    
    r, c = 0, 0
    for i in range(length):
        mirror = 2*c-i
        
        if i<r:
            p[i]=min(p[mirror], r-i) # This part is crucial. The current centered palindrome is at least of the length of its mirror IF it isnt beyond the left border of last palindrome
            
        rn = i + p[i]+1
        ln = i - p[i]-1
        
        while rn<length and ln >=0 and newS[rn]==newS[ln]:
            rn += 1
            ln -= 1
            p[i] +=1
            
        if i+p[i]>r:
            c = i
            r = i + p[i]
    maxI = p.index(max(p))
    if maxI %2 ==0: # palindrome not centered around a single literal
        return s[maxI //2 - p[maxI]//2 :maxI //2 + p[maxI]//2 ]
    else: # palindrome centered around a single literal
        return s[maxI //2 - p[maxI]//2 :maxI //2 + p[maxI]//2 +1]
