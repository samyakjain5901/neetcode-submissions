class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, cur_min = prices[0];
        for(int i=1;i<prices.size();i++){
            mx = max(mx, prices[i]-cur_min);
            cur_min = min(cur_min, prices[i]);
        }
        return mx;
    }
};
