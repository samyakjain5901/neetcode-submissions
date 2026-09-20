class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        t = [[0] * (n+1) for _ in range(2)]
        for day in range(n-1,-1,-1):
            t[1][day] = max(-prices[day]+t[0][day+1], t[1][day+1])
            t[0][day] = max(prices[day]+(t[1][day+2] if day < n-1 else 0), t[0][day+1])
        return t[1][0]