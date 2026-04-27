class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int i=0, j=0;
        vector<int>res;
        while(j < nums.size()){
            if(j-i == k){
                res.push_back(dq.front());
            }
            while(!dq.empty() && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i == k){
                if(dq.front() == nums[i]){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        res.push_back(dq.front());
        return res;
    }
};