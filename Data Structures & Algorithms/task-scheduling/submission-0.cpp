class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto ele: tasks){
            mp[ele]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto p: mp){
            pq.push({p.second, p.first});
        }
        queue<pair<char,int>>q;
        int t = 0;
        while(!pq.empty() || !q.empty()){
            t++;
            if(!pq.empty()){
                pair<int,char>top = pq.top();
                pq.pop();
                mp[top.second]--;
                if(mp[top.second] > 0){
                    q.push({top.second, t+n});
                }
            }
            if(!q.empty() && q.front().second == t){
                pair<char,int>front = q.front();
                q.pop();
                pq.push({mp[front.first], front.first});
            }
        }
        return t;
    }
};