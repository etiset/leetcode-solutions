class Solution {
private:
    pair<int, int> findLongestPalindrome(const string &s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        l++;
        r--;

        return {l, r-l+1};
    }

public:
    string longestPalindrome(string s) {
        int st = 0;
        int len = 1;

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < 2; j++){
                auto [cand_st, cand_len] = findLongestPalindrome(s, i, i+j);

                if(len < cand_len){
                    st = cand_st;
                    len = cand_len;
                }
            }
        }

        return s.substr(st, len);
    }
};