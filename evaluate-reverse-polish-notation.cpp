class Solution {
private:
    inline int calculate(char c, int a, int b){
        if(c == '+'){
            return a + b;
        }

        if(c == '-'){
            return a - b;
        }

        if(c == '*'){
            return a * b;
        }

        return a / b;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &token: tokens){
            if(isdigit(token.back())){
                st.push(stoi(token));
                continue;
            }

            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            st.push(calculate(token[0], a, b));
        }

        return st.top();
    }
};