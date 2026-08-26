class Solution {
public:
    int calculate(char c, int a, int b){
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

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string& token: tokens){
            if(isdigit(token.back())){
                st.push(stoi(token));
                continue;
            }

            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();

            st.push(calculate(token[0], x, y));
        }

        return st.top();
    }
};