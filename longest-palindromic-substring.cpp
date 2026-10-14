class Solution {
private:
    pair<int, int> findPalindrome(string &s, int st, int ed){
        while(st >= 0 && ed < s.size() && s[st] == s[ed]){
            st--;
            ed++;
        }

        return make_pair(st + 1, ed - 1);
    }

public:
    string longestPalindrome(string s) {
        int st = 0;
        int ed = 0;

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < 2; j++){
                auto [cand_st, cand_ed] = findPalindrome(s, i, i + j);

                if(cand_ed - cand_st > ed - st){
                    st = cand_st;
                    ed = cand_ed;
                }
            }
        }

        return s.substr(st, ed - st + 1);
    }
};