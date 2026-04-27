class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(auto ele: nums){
            if(mp.count(ele) > 0){
                return true;
            }
            mp[ele] = true;
        }
        return false;
    }
};