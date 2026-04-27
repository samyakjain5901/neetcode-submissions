class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i = 0, j = 0, n = s.size(), len = 0;
        while(j < n){
            if(mp.count(s[j]) > 0){
                len = max(len, j-i);
                i = max(i, mp[s[j]]+1);
            }
            mp[s[j]] = j;
            j++;
        }
        len = max(len, j-i);
        return len;
    }
};
