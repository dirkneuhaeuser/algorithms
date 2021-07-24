from collections import defaultdict

def hierholzer_algo(edges):
    """
    Problem: find a circuit/path which uses each at edge exactly one time

    Given: DIRECTED graph
    
    Requirements: 
    1. All vertices with non-zero degree belong to a single strongly connected component
    2. In-degree = Out-degree for all vertices


    idea: 
    1. start at random node if circuit else in one node with degree 1
    2. build current path by taking unused edges
    3. if you stuck somewhere backtrack (and add nodes to return list) until you still can take unuesd edges
    4. return reuslt reversed


    ACTUALLY it is just postorder traversal with dfs
    """


    
    graph = defaultdict(list)
    for i,j in edges:
        graph[i].append(j)

    degrees = {}
    for key in graph.keys():
        degrees[key] = len(graph[key])


    if len(edges) == 0:
        return


    curr_path = [edges[0][0]]
    circuit = []

    while curr_path:
        node = curr_path[-1]
        if degrees[node]>0:
            curr_path.append(graph[node].pop())
            degrees[node] -= 1
        else:
            circuit.append(curr_path.pop())

    return circuit[::-1]

print(hierholzer_algo([[0,1],[1,0],[1,2],[2,3],[3,1]]))
            
            


def alternative():
    """
    hierholzer is similiar to postorder traveral for circut as well as for paths
    """
    flightMap = defaultdict(list)

    for origin, dest in tickets:
        flightMap[origin].append(dest)


    for adjacent in flightMap.values():
        adjacent.sort(reverse=True)
        
    ret = []
        
    def dfs(origin):
        destList = flightMap[origin]
        while destList:
            dfs(destList.pop())
        ret.append(origin)



    dfs('JFK')

    return ret[::-1]
