class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s) + 1
        t = [False] * n
        t[0] = True
        for i in range(1, n):
            for j in range(i-1,-1,-1):
                if t[j] and s[j:i] in wordDict:
                    t[i] = True
        return t[n-1]