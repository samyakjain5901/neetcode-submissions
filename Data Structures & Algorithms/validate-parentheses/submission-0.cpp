class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c: s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                if(c == ')'){
                    if(top == '('){
                        st.pop();
                    } else{
                        return false;
                    }
                } else if(c == ']'){
                    if(top == '['){
                        st.pop();
                    } else{
                        return false;
                    }
                } else {
                    if(top == '{'){
                        st.pop();
                    } else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};