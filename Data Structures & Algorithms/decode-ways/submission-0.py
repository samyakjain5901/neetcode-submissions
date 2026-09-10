class Solution:
    t = {}
    def numDecodings(self, s: str) -> int:
        if len(s) == 0:
            return 1
        if s[0] == "0":
            return 0
        if s in self.t:
            return self.t[s]
        path1 = self.numDecodings(s[1:])
        path2 = 0
        if len(s) > 1 and 10 <= int(s[:2]) <= 26:
            path2 = self.numDecodings(s[2:])
        self.t[s] = path1 + path2
        return self.t[s]