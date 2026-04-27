class TimeMap {
    unordered_map<string,vector<pair<int,string>>>mp;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) == 0){
            return "";
        }
        int l = 0, h = mp[key].size()-1;
        string val = "";
        while(l <= h){
            int mid = l + (h-l)/2;
            if(mp[key][mid].first == timestamp){
                val = mp[key][mid].second;
                return val;
            }
            if(mp[key][mid].first < timestamp){
                val = mp[key][mid].second;
                l = mid+1;
            } else{
                h = mid-1;
            }
        }
        return val;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */