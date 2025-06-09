class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        vector<char> ops = {'(', '{', '['};
        vector<char> cls = {')', '}', ']'};

        for(char c: s){
            auto it = find(cls.begin(), cls.end(), c);

            if(it == cls.end()){
                st.push(c);
                continue;
            }

            int idx = it - cls.begin();
            
            if(st.empty() || st.top() != ops[idx]){
                return false;
            }

            st.pop();
        }

        return st.empty();
    }
};