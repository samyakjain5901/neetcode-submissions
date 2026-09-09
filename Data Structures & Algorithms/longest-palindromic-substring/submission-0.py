class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        t = [[False] * n for _ in range(n)]
        for i in range(n):
            t[i][i] = True
        longest = s[0]
        for l in range(2,n+1):
            for i in range(n-l+1):
                j = i+l-1
                t[i][j] = s[i] == s[j] and (i+1 > j-1 or t[i+1][j-1])
                if t[i][j]:
                    longest = s[i:j+1]
        return longest