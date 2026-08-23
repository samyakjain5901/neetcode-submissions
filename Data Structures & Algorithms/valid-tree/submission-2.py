class Solution:
    def _hasCycle(self, i: int, adj: List[List[int]], visited: List[bool], p: int) -> bool:
        visited[i] = True
        for n in adj[i]:
            if n == p:
                continue   
            if visited[n] or (not visited[n] and self._hasCycle(n, adj, visited, i)):
                return True
        return False

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n-1:
            return False
        visited = [False] * n
        adj = [[] for _ in range(n)]
        for s, d in edges:
            adj[s].append(d)
            adj[d].append(s)
        if self._hasCycle(0, adj, visited, -1) or not all(visited):
            return False
        return True
                