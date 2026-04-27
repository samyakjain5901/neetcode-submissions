class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto s: tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                if(s == "+"){
                    st.push(t2 + t1);
                } else if(s == "-"){
                    st.push(t2 - t1);
                } else if(s == "*"){
                    st.push(t2 * t1);
                } else {
                    st.push(t2 / t1);
                }
            } else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};