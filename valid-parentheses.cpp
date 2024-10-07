class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        vector<pair<char, char>> paren_pairs{{'[', ']'}, {'(', ')'}, {'{', '}'}};

        for(char c: s){
            if(c == '[' || c == '(' || c == '{'){
                st.push(c);
                continue;
            }
            
            for(auto& [op, cl]: paren_pairs){
                if(c == cl){
                    if(st.empty() || st.top() != op){
                        return false;
                    }

                    st.pop();
                    break;
                }
            }
        }

        return st.empty();
    }
};