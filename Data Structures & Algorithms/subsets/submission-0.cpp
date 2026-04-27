class Solution {
    void helper(vector<int> &nums, vector<vector<int>>&res, vector<int>v, int start, int end){
        if(start >= end){
            res.push_back(v);
            return;
        }
        helper(nums, res, v, start+1, end);
        v.push_back(nums[start]);
        helper(nums, res, v, start+1, end);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        helper(nums, res, v, 0, nums.size());
        return res;
    }
};