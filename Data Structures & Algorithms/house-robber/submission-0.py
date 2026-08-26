class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        t = [0] * (n+1)
        t[n-1] = nums[n-1]
        for i in range(n-2, -1, -1):
            t[i] = max(t[i+1], nums[i] + t[i+2])
        return t[0]