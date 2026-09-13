class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        t = [1] * n
        lis = 1
        for i in range(1,n):
            for j in range(i-1,-1,-1):
                if nums[i] > nums[j]:
                    t[i] = max(t[i], t[j]+1)
                    lis = max(lis, t[i])
        return lis

