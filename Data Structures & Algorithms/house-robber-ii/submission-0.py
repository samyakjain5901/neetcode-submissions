class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        t1, t2 = [0] * n, [0] * n
        t1[n-2] = nums[n-2]
        for i in range(n-3,-1,-1):
            t1[i] = max(t1[i+1], nums[i]+t1[i+2])
        t2[1] = nums[1]
        for i in range(2,n):
            t2[i] = max(t2[i-1], nums[i]+t2[i-2])
        return max(t2[n-1], t1[0])