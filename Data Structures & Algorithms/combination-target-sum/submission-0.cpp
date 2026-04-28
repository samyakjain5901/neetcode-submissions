class Solution {
    void helper(vector<int>& candidates, int target, vector<vector<int>>& combs, vector<int>v, int start, int n){
        if(target == 0){
            combs.push_back(v);
            return;
        }
        if(start == n || target < 0){
            return;
        }
        helper(candidates, target, combs, v, start+1, n);
        v.push_back(candidates[start]);
        helper(candidates, target-candidates[start], combs, v, start, n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>combs;
        vector<int>v;
        helper(candidates, target, combs, v, 0, candidates.size());
        return combs;
    }
};