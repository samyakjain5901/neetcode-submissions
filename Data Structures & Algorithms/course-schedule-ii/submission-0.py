class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0] * numCourses
        adj = [[] for _ in range(numCourses)]
        for d, s in prerequisites:
            indegree[d] += 1
            adj[s].append(d)
        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        order = []
        while q:
            front = q.popleft()
            order.append(front)
            for n in adj[front]:
                indegree[n] -= 1
                if indegree[n] == 0:
                    q.append(n)
        for d in indegree:
            if d > 0:
                return []
        return order
        