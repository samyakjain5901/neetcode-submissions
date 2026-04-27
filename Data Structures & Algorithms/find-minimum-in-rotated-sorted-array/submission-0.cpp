class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1, mid;
        while(l <= h){
            mid = l + (h-l)/2;
            if(nums[h] > nums[mid]){
                h = mid;
            } else{
                l = mid+1;
            }
        }
        return nums[mid];
    }
};