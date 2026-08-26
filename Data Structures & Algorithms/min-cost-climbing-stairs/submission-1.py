class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        t = [float('-inf')] * n
        t[n-1], t[n-2] = cost[n-1], cost[n-2]
        for i in range(n-3,-1,-1):
            t[i] = cost[i] + min(t[i+1], t[i+2])
        return min(t[0], t[1])