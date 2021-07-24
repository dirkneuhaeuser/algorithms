def mst_prim(n: int, edges: List[List[int]]):
    '''
    - heap for intersectional edges and marker array for nodes:
    - until heap not empty take less weighted intersectional edge, mark new node and add new intersectional
    - add weight of all chosen intersectional edges
    '''
    graph = defaultdict(list)
    for u,v,w in edges:
        graph[u].append((v,w))
        graph[v].append((u,w))

    def prim():
        '''
        returns the weight of the MST of graph
        '''
        heap = []
        marked = [0]*n

        def seen(i):
            marked[i]= True
            for u, w in graph[i]:
                if not marked[u]: heapq.heappush(heap, (w, u, i))

        seen(0)
        ret = 0
        while heap:
            w, u, v = heapq.heappop(heap)
            if marked[u] == marked[v]: continue
            if marked[u]: seen(v)
            if marked[v]: seen(u)
            ret += w
        return ret
    
    return prim()
