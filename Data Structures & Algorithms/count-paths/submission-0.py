class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        t = [[1] * n for _ in range(m)]
        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                t[i][j] = t[i+1][j] + t[i][j+1]
        return t[0][0]