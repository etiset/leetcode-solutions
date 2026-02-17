class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        vector<char> ops = {'(', '{', '['};
        vector<char> cls = {')', '}', ']'};

        for(char c: s){
            auto it = find(ops.begin(), ops.end(), c);

            if(it != ops.end()){
                st.push(c);
                continue;
            }

            if(st.empty()){
                return false;
            }

            int idx = find(cls.begin(), cls.end(), c) - cls.begin();
            
            if(st.top() != ops[idx]){
                return false;
            }

            st.pop();
        }

        return st.empty();
    }
};
