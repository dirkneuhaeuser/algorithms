class Solution:
    """
    lc: 1579
    idea: 2 spanning treees for alice and bob. Implementation via Union Find datastructure or also called disjoint-set datastructure
    """
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        dsuA = UnionFindDatastructure(n)
        dsuB = UnionFindDatastructure(n)

        ret = 0
        for typeE, u, v in edges:
            if typeE == 3:
                if not dsuA.union(u, v):
                    ret += 1
                dsuB.union(u, v)
                    
        for typeE, u, v in edges:
            if typeE == 2:
                if not dsuB.union(u,v):
                    ret += 1
            if typeE == 1:
                if not dsuA.union(u,v):
                    ret += 1                    

        return ret if dsuA.size() == dsuB.size() == n else -1
        
class UnionFindDatastructure:
    """
    also called DSU
    """
    def __init__(self, N):
        self.parent = {}
        self.sz = {}
        for i in range(1,N+1):
            self.parent[i]=i
            self.sz[i] = 1

    def find(self, i):
        while self.parent[i] != i:
            i = self.parent[i]
        return i

    def union(self, i, j):
        par, kid = self.find(i), self.find(j)
        if par == kid:
            return False
        if self.sz[kid] > self.sz[par]:
            par, kid = kid, par
        self.parent[kid] = par
        self.sz[par] += self.sz[kid]
        return True

    def size(self):
        return self.sz[self.find(1)]
