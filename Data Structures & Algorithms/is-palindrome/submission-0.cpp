class Solution {
public:
    bool isPalindrome(string s) {
        string trimmed;
        for(auto c: s){
            if((c >= 97 && c <= 122) || (c >= 48 && c <= 57)){
                trimmed += c;
            } else if(c >= 65 && c <= 90){
                trimmed += char(c+32);
            }
        }
        int i=0, j=trimmed.size()-1;
        while(i < j){
            if(trimmed[i] != trimmed[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
