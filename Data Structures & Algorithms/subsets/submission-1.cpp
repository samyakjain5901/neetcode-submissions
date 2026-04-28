class Solution {
    void helper(vector<int> &nums, vector<vector<int>>&res, vector<int>v, int start, int n){
        if(start >= n){
            res.push_back(v);
            return;
        }
        helper(nums, res, v, start+1, n);
        v.push_back(nums[start]);
        helper(nums, res, v, start+1, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        helper(nums, res, v, 0, nums.size());
        return res;
    }
};