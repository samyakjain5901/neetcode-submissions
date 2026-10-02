class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n1 + n2 != n3:
            return False
        t = [[False] * (n2+1) for _ in range(n1+1)]
        t[0][0] = True
        for i in range(1,n2+1):
            t[0][i] = s2[i-1] == s3[i-1] and t[0][i-1]
        for i in range(1,n1+1):
            t[i][0] = s1[i-1] == s3[i-1] and t[i-1][0]
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if s1[i-1] == s3[i+j-1] and s2[j-1] != s3[i+j-1]:
                    t[i][j] = t[i-1][j]
                elif s2[j-1] == s3[i+j-1] and s1[i-1] != s3[i+j-1]:
                    t[i][j] = t[i][j-1]
                elif s1[i-1] == s3[i+j-1] and s2[j-1] == s3[i+j-1]:
                    t[i][j] = t[i][j-1] or t[i-1][j]
        return t[n1][n2]
        