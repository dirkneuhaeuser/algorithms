class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        '''
        Impletmentation via Floyed
        '''
        
        dist = [[float('inf')]* n for _ in range(n)]
        
        for i,j,d in edges:
            dist[i][j]=d
            dist[j][i]=d
        
        for i in range(n):
            dist[i][i]=0
        
        #### Floyed:
        for k in range(n):
            for j in range(n):
                for i in range(n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
                    

        ret = {sum([x<=distanceThreshold for x in dist[i]]): i for i in range(n)} ##Sexy dict so save the latest city with the same distance
        
        return ret[min(ret)] # get the city with minimal distance
