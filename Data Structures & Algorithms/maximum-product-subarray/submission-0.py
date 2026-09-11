class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr, mx, mn, res = nums[0], nums[0], nums[0], nums[0]
        for n in nums[1:]:
            tmp_mx = max(n, n * mx, n * mn)
            mn = min(n, n * mx, n * mn)
            mx = tmp_mx

            res = max(res, mx)
        return res
        