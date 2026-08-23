class Solution:
    def _dfs(self, i: int, adj: List[List[int]], visited: List[bool]) -> None:
        visited[i] = True
        for n in adj[i]:
            if not visited[n]:
                self._dfs(n, adj, visited)

    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        visited = [False] * n
        for s, d in edges:
            adj[s].append(d)
            adj[d].append(s)
        cnt = 0
        for i in range(n):
            if not visited[i]:
                self._dfs(i, adj, visited)
                cnt += 1
        return cnt