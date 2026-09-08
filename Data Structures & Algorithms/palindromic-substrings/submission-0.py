class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        t = [[0] * n for _ in range(n)]
        for i in range(n):
            t[i][i] = 1
        for l in range(2,n+1):
            for i in range(n-l+1):
                j = i+l-1
                if s[i] == s[j] and (i+1 > j-1 or t[i+1][j-1] == 1):
                    t[i][j] = 1
        cnt = sum(sum(row) for row in t)
        return cnt
