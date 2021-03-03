class Solution:
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        """
        1627 Graph Connectivity with Threshold
        Idea: Create A DSU based on the sieve of eratosthones -> starting from threshold, unite all multiple of current
        """
        dsu = DSU(n+1)
        # sieve of erasthones:
        for i in range(threshold + 1, n+1):
            for j in range(i*2, n+1, i): # here i**2 doesnt work because of the threshold, some previous may not have been considered yet
                dsu.union(i,j)
        ret = []
        for i,j in queries:
            ret.append(dsu.find(i) == dsu.find(j))
        return ret
        
        
        
class DSU:
    def __init__(self, n):
        self.parents = [i for i in range(n)]
        self.rank = [1 for i in range(n)]
        
        # notice, lists are way faster than hasmaps
        # self.rank = {}
        # self.parents = {}
        # for i in range(n):
        #     self.parents[i] = i
        #     self.rank[i] = 1

    def find(self, i):
        while self.parents[i] != i:
            i = self.parents[i]
        return i

    def union(self, i, j):
        ri, rj = self.find(i), self.find(j)
        if ri == rj:
            return False
        else:
            if self.rank[i] < self.rank[j]:
                # ri is new parent
                ri, rj = rj, ri
            if self.rank[i] == self.rank[j]:
                self.rank[i] +=1
            self.parents[rj] = ri
            return True

