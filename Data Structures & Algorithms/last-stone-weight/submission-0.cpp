class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto w: stones){
            pq.push(w);
        }
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int res = abs(x - y);
            if(res > 0){
                pq.push(res);
            }
        }
        if(!pq.empty()){
            return pq.top();
        }
        return 0;
    }
};