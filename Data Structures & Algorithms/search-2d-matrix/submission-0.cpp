class Solution {
    bool binarySearch(vector<int>& arr, int target){
        int l = 0, h = arr.size()-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] == target){
                return true;
            }
            if(arr[mid] > target){
                h = mid-1;
            } else{
                l = mid+1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size()-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(matrix[mid][0] == target){
                return true;
            }
            if(matrix[mid][0] > target){
                h = mid-1;
            } else{
                if(mid+1 == matrix.size() || matrix[mid+1][0] > target){
                    return binarySearch(matrix[mid], target);
                } else{
                    l = mid+1;
                }
            }
        }
        return false;
    }
};