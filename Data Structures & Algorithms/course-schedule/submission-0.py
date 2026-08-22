class Solution:
    def _hasCycle(self, i: int, adj_list: List[List[int]], visited: List[bool], dfs_visited: List[bool]) -> bool:
        visited[i] = True
        dfs_visited[i] = True
        for n in adj_list[i]:
            if dfs_visited[n] or (not visited[n] and self._hasCycle(n, adj_list, visited,dfs_visited)):
                return True
        dfs_visited[i] = False
        return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj_list = [[] for _ in range(numCourses)]
        for d, s in prerequisites:
            adj_list[s].append(d)
        visited = [False] * numCourses
        dfs_visited = [False] * numCourses
        for i in range(numCourses):
            if not visited[i] and self._hasCycle(i, adj_list, visited, dfs_visited):
                return False
        return True