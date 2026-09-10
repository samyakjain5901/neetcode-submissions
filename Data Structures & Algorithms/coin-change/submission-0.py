class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        t = [[float('inf')] * (n+1) for _ in range(amount+1)]
        for i in range(n+1):
            t[0][i] = 0
        for i in range(1,amount+1):
            for j in range(1,n+1):
                if i >= coins[j-1]:
                    t[i][j] = min(t[i][j], 1+t[i-coins[j-1]][j])
                t[i][j] = min(t[i][j], t[i][j-1])
        if t[amount][n] == float('inf'):
            return -1
        return t[amount][n]
        