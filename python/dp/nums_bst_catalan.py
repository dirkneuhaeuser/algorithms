class Solution:
    def numTreesDpCatalanNumber(self, n: int) -> int:
        '''
        G(n) = Num. of BST with len n
        Basecase: G(0) = 1 = G(1)
        F(i,n) = Num of BST with len n where i is root
        G(n) = F(1,n) + F(2,n) + ... + F(n,n)
        BUT: F(i,n) = G(i-1) * G(n-i)
        -> G(n) = G(0) * G(n-1) + ...+ G(n-1)*G(0)
        which is the catalan Number :)
        G(n) = (2n)! / ( n!  (n+1)! )



        Count brackets:
        you habe already n pairs add another pair-> 2n + 2 new brackts:
        Where can you put these brackets?
        [2i brackts] + 2(n-i) brackets


        number of ways to go from (0,0) to (n,n) without crossing diagonal?
        total ways (with crossing) = (2n) over n
        Above (illigal ways) = (2n)! / (n+1)!*(n-1)! = (2n) over (n+1)  # very diffiuclty
        Catalan (legal moves) ) (2n) over n - (2n) over (n+1)
        '''
        g = [0]*(n+1)
        g[0], g[1] = 1, 1
        for i in range(2, n+1):
            for j in range(i):
                g[i] += g[j]*g[i-1-j]

        return g[-1]

    def numTreesCatalanNumber(self, n: int) -> int:
        '''
        G(n) = (2n)! / ( n!  (n+1)! )
        '''
        return math.factorial(2*n) // ( math.factorial(n) * math.factorial(n+1))

    def numTreesDP(self, n: int) -> int:
        if n == 0:
            return 0
        @lru_cache(None)
        def generate(start, end):
            '''
            provides all perms of the tree, which begins at start and ends in end:
            '''
            if start >= end +1:
                return 1
            ret = 0
            for i in range(start, end+1):
                left = generate(start, i-1)
                right = generate(i+1, end)
                ret += left*right
            return ret
    
        return generate(1,n)
        
