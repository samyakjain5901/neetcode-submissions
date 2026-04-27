class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int start = 0, max_freq = 0, res = 0;
        for(int end=0;end<s.size();end++){
            mp[s[end]]++;
            max_freq = max(max_freq, mp[s[end]]);
            while((end-start+1) - max_freq > k){
                mp[s[start]]--;
                start++;
            }
            res = max(res, end-start+1);
        }
        return res;
    }
};
