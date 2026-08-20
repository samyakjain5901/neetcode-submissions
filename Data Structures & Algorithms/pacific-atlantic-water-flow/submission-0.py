xy = [(0,1),(1,0),(0,-1),(-1,0)]
class Solution:
    def _dfs(self, i: int, j: int, m: int, n: int, heights: List[List[int]], ocean: List[List[bool]]) -> None:
        for x, y in xy:
            ni, nj = i+x, j+y
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                continue
            if not ocean[ni][nj] and heights[ni][nj] >= heights[i][j]:
                ocean[ni][nj] = True
                self._dfs(ni, nj, m, n, heights, ocean)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        atlantic, pacific = [[False] * n for _ in range(m)], [[False] * n for _ in range(m)]
        for i in range(n):
            pacific[0][i] = True
            atlantic[m-1][i] = True
        for i in range(m):
            pacific[i][0] = True
            atlantic[i][n-1] = True
        for i in range(n):
            self._dfs(m-1, i, m, n, heights, atlantic)
            self._dfs(0, i, m, n, heights, pacific)
        for i in range(m):
            self._dfs(i, n-1, m, n, heights, atlantic)
            self._dfs(i, 0, m, n, heights, pacific)
        result = []
        for i in range(m):
            for j in range(n):
                if atlantic[i][j] and pacific[i][j]:
                    result.append([i, j])
        return result