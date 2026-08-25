class Solution:
    def climbStairs(self, n: int) -> int:
        if n in (0, 1, 2):
            return n
        t = [0] * (n+1)
        t[1], t[2] = 1, 2
        for i in range(3,n+1):
            t[i] = t[i-1] + t[i-2]
        return t[n]