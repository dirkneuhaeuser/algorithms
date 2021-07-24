def fleury():
    """
    fleury algo:

    Requirements:
    Undirected Graph
    zero or two vertices with odd degree -> if two, start in one of them(path rather than circuit)

    idea: 
    in current node, 
        -if there is only one adjacent -> go there
        -if there are several, avoid breaking bridges (you can't come back)


    """
    
        
    graph = defaultdict(list)
    for x, y in tickets:
        graph[x].append(y)

        
    
    def dfs(node, visited):
        if node in visited:
            return -1
        else:
            visited.add(node)
            for adjacent in graph[node]:
                dfs(adjacent, visited)
        return len(visited)
            
    ret = []
    def euler_path(node):
        ret.append(node)
        if len(graph[node]) == 0:
            return
        if len(graph[node]) == 1:
            euler_path(graph[node].pop())
        else:
            adjacents = graph[node]
            reachable = dfs(node, set())
            for adjacent in adjacents:
                graph[node].remove(adjacent)
                if dfs(node, set()) == reachable:
                    euler_path(adjacent)
                    break
                else:
                    graph[node].append(adjacent)
            else:
                euler_path(graph[node].pop(0))
    
    euler_path("start")
    return ret
            
