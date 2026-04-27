class Solution {
    bool checkIfSubset(unordered_map<char,int>&mp1, unordered_map<char,int>&mp2){
        for(auto p: mp2){
            if(mp1.count(p.first) == 0 || mp1[p.first] < p.second){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp_s, mp_t;
        for(auto c: t){
            mp_t[c]++;
        }
        int l = 0, r = 0, mx_l = 0, start = 0;
        while(r < s.size()){
            if(checkIfSubset(mp_s, mp_t)){
                if(mx_l == 0 || mx_l > r-l){
                    mx_l = r-l;
                    start = l;
                }
                mp_s[s[l]]--;
                l++;
            } else{
                mp_s[s[r]]++;
                r++;
            }
        }
        while(l < r && checkIfSubset(mp_s, mp_t)){
            if(mx_l == 0 || mx_l > r-l){
                mx_l = r-l;
                start = l;
            }
            mp_s[s[l]]--;
            l++;
        }
        return s.substr(start, mx_l);
    }
};