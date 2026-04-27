class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto c: s){
            mp[c]++;
        }
        for(auto c: t){
            if(mp.count(c) > 0){
                mp[c]--;
            } else{
                return false;
            }
        }
        for(auto &p: mp){
            if(p.second != 0){
                return false;
            }
        }
        return true;
    }
};
