class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1)+1, len(text2)+1
        t = [[0] * n for _ in range(m)]
        for i in range(1,m):
            for j in range(1,n):
                if text1[i-1] == text2[j-1]:
                    t[i][j] = 1+t[i-1][j-1]
                else:
                    t[i][j] = max(t[i-1][j], t[i][j-1])
        return t[m-1][n-1]