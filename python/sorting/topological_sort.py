class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        '''
        Using topological sorting(BFS) Everytime there in a new in_grad == 0 node, add it to queue and subtract in_grad of all after
        '''
        in_grad = [0]*numCourses
        
        g = [set() for _ in range(numCourses)]
        for i, p in enumerate(prerequisites):
            g[p[1]].add(p[0])
            in_grad[p[0]] += 1

        
        queue = [i for i in range(len(in_grad)) if in_grad[i] == 0]
        
        # order = []

        counter = 0
        while queue:
            counter += 1
            course = queue.pop()
            # order.append(course)
            for adj in list(g[course]):
                in_grad[adj] -= 1
                if in_grad[adj] == 0:
                    queue.append(adj)
        return counter == numCourses
