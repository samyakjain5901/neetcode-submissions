class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        n = len(coins)
        t = [[0] * (amount+1) for _ in range(n+1)]
        for i in range(n+1):
            t[i][0] = 1
        for i in range(1,n+1):
            for j in range(1,amount+1):
                skip_den_way = t[i-1][j]
                take_den_way = t[i][j-coins[i-1]] if coins[i-1] <= j else 0
                t[i][j] = skip_den_way + take_den_way
        return t[n][amount]