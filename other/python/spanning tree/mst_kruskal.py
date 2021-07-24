class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        '''
        Kruskal-algo for MST: based on union-find: sort edges with respect to their weights.
        If the both nodes of an edge are not in the same "tree", unify them and add edge to result! :)
        '''
        edges.sort(key = lambda x: x[2])
        union_ds = UnionFindDatastructure(n)
        
        ans = 0
        for i,j,w in edges:
            if union_ds.union(i,j):
                ans += w
        return ans
    
class UnionFindDatastructure:
    def __init__(self,n):
        self.parent = {}
        self.rank = {}
        for i in range(n):
            self.parent[i]=i
            self.rank[i] = 1

    def find(self,i):
        while self.parent[i] != i:
            i = self.parent[i]
        return i
    
    def union(self, i,j):
        root_i, root_j = self.find(i), self.find(j)
        if root_i == root_j:
            return False
        if self.rank[root_i] > self.rank[root_j]:
            self.parent[root_j] = root_i
        elif self.rank[root_i] < self.rank[root_j]:
            self.parent[root_i] = root_j
        else:
            self.parent[root_i] = root_j
            self.rank[root_i] += 1
        return True


