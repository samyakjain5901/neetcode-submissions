class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i = 0, j = 0, n = s.size(), len = 0;
        while(j < n){
            if(mp.count(s[j]) > 0){
                i = max(i, mp[s[j]]+1);
                mp.erase(s[j]);
            }
            mp[s[j]] = j;
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};
