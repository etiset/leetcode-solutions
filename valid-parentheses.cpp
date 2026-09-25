class Solution {
public:
    bool isValid(string s) {
        vector<char> ops = {'(', '{', '['};
        vector<char> eds = {')', '}', ']'};
        
        stack<char> st;

        for(char c: s){
            auto it = find(eds.begin(), eds.end(), c);

            if(it == eds.end()){
                st.push(c);
            }

            else{
                int idx = it - eds.begin();

                if(st.empty() || st.top() != ops[idx]){
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};