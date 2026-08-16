from collections import deque

xy = [(0,1),(1,0),(0,-1),(-1,0)]
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n, rot, fresh = len(grid), len(grid[0]), 2, 1
        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == rot:
                    q.append((i,j,0))
        tot_min = 0
        while q:
            i, j, t = q.popleft()
            tot_min = t
            for x, y in xy:
                ni, nj = i+x, j+y
                if ni < 0 or ni >= m or nj < 0 or nj >= n:
                    continue
                if grid[ni][nj] == fresh:
                    q.append((ni,nj,t+1))
                    grid[ni][nj] = rot
        for i in range(m):
            for j in range(n):
                if grid[i][j] == fresh:
                    return -1
        return tot_min
                