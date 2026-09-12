class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_tn, min_tn, max_prod = nums[0], nums[0], nums[0]
        for cur_num in nums[1:]:
            tmp_max_tn = max(cur_num, max_tn * cur_num, min_tn * cur_num)
            min_tn = min(cur_num, max_tn * cur_num, min_tn * cur_num)
            max_tn = tmp_max_tn

            max_prod = max(max_prod, max_tn)
        return max_prod
        
