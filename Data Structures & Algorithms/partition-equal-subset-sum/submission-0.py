class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total%2 != 0:
            return False
        n = len(nums)+1
        psum = total//2
        t = [[False] * (psum + 1) for _ in range(n)]
        for i in range(n):
            t[i][0] = True
        for i in range(1,n):
            for j in range(1,psum+1):
                if nums[i-1] <= j:
                    t[i][j] = t[i][j] or t[i-1][j-nums[i-1]]
                t[i][j] = t[i][j] or t[i-1][j]
        return t[n-1][psum]