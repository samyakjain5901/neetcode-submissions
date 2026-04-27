class Solution {
    void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& comb){
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                comb.push_back(nums1[i]);
                i++;
            } else{
                comb.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()){
            comb.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            comb.push_back(nums2[j]);
            j++;
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>comb;
        merge(nums1, nums2, comb);
        int size = comb.size();
        if(size&1){
            return comb[(size-1)/2];
        } else{
            double mid = (double)comb[(size/2)-1] + comb[size/2];
            return mid/2;
        }
    }
};