from collections import deque

xy = [(0,1),(1,0),(0,-1),(-1,0)]
class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        m, n = len(grid), len(grid[0])
        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    q.append((i,j,grid[i][j]))
        while q:
            i, j, d = q.popleft()
            for x, y in xy:
                ni, nj = i+x, j+y
                if ni < 0 or ni >= m or nj < 0 or nj >= n:
                    continue
                if grid[ni][nj] == 2**31-1:
                    q.append((ni,nj,d+1))
                    grid[ni][nj] = d+1
