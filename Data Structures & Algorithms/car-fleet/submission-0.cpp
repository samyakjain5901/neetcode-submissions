class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int,int>>car;
        for(int i=0;i<position.size();i++){
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), greater<pair<int,int>>());
        int cnt = 0;
        for(auto p: car){
            double time = (double)(target-p.first)/p.second;
            if(st.empty()){
                st.push(time);
                continue;
            }
            if(time > st.top()){
                st.pop();
                st.push(time);
                cnt++;
            }
        }
        if(!st.empty()){
            cnt++;
        }
        return cnt;
    }
};