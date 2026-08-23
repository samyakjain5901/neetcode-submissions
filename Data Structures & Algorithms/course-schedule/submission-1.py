from collections import deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj = [[] for _ in range(numCourses)]
        for d, s in prerequisites:
            indegree[d] += 1
            adj[s].append(d)
        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        while q:
            front = q.popleft()
            for n in adj[front]:
                indegree[n] -= 1
                if indegree[n] == 0:
                    q.append(n)
        for i in range(numCourses):
            if indegree[i] > 0:
                return False
        return True