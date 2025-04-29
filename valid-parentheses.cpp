class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        vector<char> ops = {'(', '[', '{'};
        vector<char> cls = {')', ']', '}'};

        for(char c: s){
            int cl_idx = -1;

            for(int i = 0; i < 3; i++){
                if(c == cls[i]){
                    cl_idx = i;
                }
            }

            if(cl_idx == -1){
                st.push(c);
                continue;
            }

            if(st.empty() || st.top() != ops[cl_idx]){
                return false;
            }

            st.pop();
        }

        return st.empty();
    }
};