class Solution {
private:
    pair<int, int> expandPalindrome(string& s, int st, int ed){
        while(st >= 0 && ed < s.size() && s[st] == s[ed]){
            st--;
            ed++;
        }

        return make_pair(st+1, ed-st-1);
    }

public:
    string longestPalindrome(string s) {
        int st = 0;
        int plen = 1;

        for(int i = 0; i < s.size(); i++){
            auto [st1, plen1] = expandPalindrome(s, i, i);
            auto [st2, plen2] = expandPalindrome(s, i, i+1);

            if(plen1 > plen){
                st = st1;
                plen = plen1;
            }

            if(plen2 > plen){
                st = st2;
                plen = plen2;
            }
        }

        return s.substr(st, plen);
    }
};