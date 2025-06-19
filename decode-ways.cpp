class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> st;

        for(int i = 1; i < 27; i++){
            st.insert(to_string(i));
        }

        int prev2 = 0;
        int prev1 = 1;

        for(int i = 0; i < s.size(); i++){
            int curr = (st.count(s.substr(i, 1)) ? prev1 : 0);

            if(i && st.count(s.substr(i-1, 2))){
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};