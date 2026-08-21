xy = [(0,1),(1,0),(0,-1),(-1,0)]
class Solution:
    def _dfs(self, i: int, j: int, m: int, n: int, board: List[List[str]], visited: List[List[bool]]) -> None:
        visited[i][j] = True
        for x, y in xy:
            ni, nj = i+x, j+y
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                continue
            if board[ni][nj] == 'O' and not visited[ni][nj]:
                self._dfs(ni, nj, m, n, board, visited)

    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        visited = [[False] * n for _ in range(m)]
        for i in range(n):
            if board[0][i] == 'O':
                self._dfs(0, i, m, n, board, visited)
            if board[m-1][i] == 'O':
                self._dfs(m-1, i, m, n, board, visited)
        for i in range(m):
            if board[i][0] == 'O':
                self._dfs(i, 0, m, n, board, visited)
            if board[i][n-1] == 'O':
                self._dfs(i, n-1, m, n, board, visited)
        for i in range(1,m-1):
            for j in range(1,n-1):
                if board[i][j] == 'O' and not visited[i][j]:
                    board[i][j] = 'X'