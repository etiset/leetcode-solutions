class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> valids;

        for(int i = 1; i <= 26; i++){
            valids.insert(to_string(i));
        }

        int prev2 = 1;
        int prev1 = 1;

        for(int i = 0; i < s.size(); i++){
            int prev = (s[i] != '0') ? prev1 : 0;

            if(i > 0 && valids.count(s.substr(i-1, 2))){
                prev += prev2;
            }

            prev2 = prev1;
            prev1 = prev;
        }

        return prev1;
    }
};