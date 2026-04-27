class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>>pq;
        for(auto p: points){
            pq.push({p[0]*p[0]+p[1]*p[1], p[0], p[1]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>>closest;
        while(!pq.empty()){
            vector<int>top = pq.top();
            pq.pop();
            closest.push_back({top[1], top[2]});
        }
        return closest;
    }
};