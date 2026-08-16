xy = [(0, 1),(1, 0),(0, -1),(-1, 0)]
class Solution:
    def _dfs(self, i: int, j: int, grid: List[List[str]], visited: List[List[bool]], m: int, n: int):
        visited[i][j] = True
        for x, y in xy:
            ni, nj = i+x, j+y
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                continue
            if grid[ni][nj] == "1" and not visited[ni][nj]:
                self._dfs(ni, nj, grid, visited, m, n)

    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1" and not visited[i][j]:
                    self._dfs(i, j, grid, visited, m, n)
                    cnt += 1
        return cnt