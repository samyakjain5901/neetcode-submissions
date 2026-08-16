xy = [(0,1),(1,0),(0,-1),(-1,0)]
class Solution:
    def _dfs(self, i: int, j: int, grid: List[List[int]], visited: List[List[bool]], m: int, n: int):
        visited[i][j] = True
        area = 1
        for x, y in xy:
            ni, nj = i+x, j+y
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                continue
            if grid[ni][nj] == 1 and not visited[ni][nj]:
                area += self._dfs(ni, nj, grid, visited, m, n)
        return area


    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        max_area = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and not visited[i][j]:
                    max_area = max(max_area, self._dfs(i, j, grid, visited, m, n))
        return max_area