class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        sn = sum(nums)
        target = abs(target)
        if (target + sn)%2 != 0 or target > sn:
            return 0
        W = (target + sn) // 2
        t = [[0]*(W+1) for _ in range(n+1)]
        t[0][0] = 1
        for i in range(1,n+1):
            for j in range(0,W+1):
                if nums[i-1] <= j:
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]]
                else:
                    t[i][j] = t[i-1][j]
        return t[n][W]