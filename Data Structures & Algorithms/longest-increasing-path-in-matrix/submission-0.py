class Solution:
    _xy = [(0,1),(1,0),(0,-1),(-1,0)]
    def _fetchMaxLen(self, matrix: list[list[int]], t: list[list[int]], i: int, j: int, m: int, n: int) -> int:
        if t[i][j] > 0:
            return t[i][j]
        t[i][j] = 1
        for x, y in self._xy:
            ni, nj = i + x, j + y
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                continue
            if matrix[i][j] < matrix[ni][nj]:
                t[i][j] = max(t[i][j], 1 + self._fetchMaxLen(matrix, t, ni, nj, m, n))
        return t[i][j]

    def longestIncreasingPath(self, matrix: list[list[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        t = [[0] * n for _ in range(m)]
        res = 0
        for i in range(m):
            for j in range(n):
                t[i][j] = self._fetchMaxLen(matrix, t, i, j, m, n)
                res = max(res, t[i][j])
        return res