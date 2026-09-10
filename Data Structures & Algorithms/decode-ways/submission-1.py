class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        t = [0] * (n+1)
        t[n] = 1
        for i in range(n-1,-1,-1):
            if s[i] != "0":
                t[i] += t[i+1]
            if i+1 < n and 10 <= int(s[i:i+2]) <= 26:
                t[i] += t[i+2]
        return t[0]