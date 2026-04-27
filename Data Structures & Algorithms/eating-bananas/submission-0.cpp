class Solution {
    bool pilePossible(vector<int>& piles, int p, int h){
        long long cnt = 0;
        for(int i=0;i<piles.size();i++){
            cnt += ceil((double)piles[i]/p);
        }
        return cnt <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(pilePossible(piles, mid, h)){
                k = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        return k;
    }
};