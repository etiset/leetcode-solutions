class Solution {
private:
    pair<int, int> getTopTwo(stack<int>& st){
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        return make_pair(b, a);
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string tok: tokens){
            if(tok == "+"){
                auto [a, b] = getTopTwo(st);
                st.push(a + b);
            }

            else if(tok == "-"){
                auto [a, b] = getTopTwo(st);
                st.push(a - b);
            }

            else if(tok == "*"){
                auto [a, b] = getTopTwo(st);
                st.push(a * b);
            }

            else if(tok == "/"){
                auto [a, b] = getTopTwo(st);
                st.push(a / b);
            }

            else{
                st.push(stoi(tok));
            }
        }

        return st.top();
    }
};