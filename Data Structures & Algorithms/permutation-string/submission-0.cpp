class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp_1;
        for(auto c: s1){
            mp_1[c]++;
        }
        unordered_map<char,int>mp_2;
        int left=0;
        for(int right=0;right<s2.size();right++){
            if(right < s1.size()){
                mp_2[s2[right]]++;
            } else{
                mp_2[s2[left]]--;
                if(mp_2[s2[left]] == 0){
                    mp_2.erase(s2[left]);
                }
                left++;
                mp_2[s2[right]]++;
            }
            if(mp_1 == mp_2){
                return true;
            }
        }
        return false;
    }
};
