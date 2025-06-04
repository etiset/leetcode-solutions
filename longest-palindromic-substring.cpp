class Solution {
public:

    string longestPalindrome(string s) {
        int st = 0;
        int plen = 1;

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; true; j++){
                int l = i - j;
                int r = i + j;

                if(l < 0 || r == s.size()){
                    break;
                }

                if(s[l] != s[r]){
                    break;
                }

                int clen = r - l + 1;

                if(clen > plen){
                    st = l;
                    plen = clen;
                }
            }

            for(int j = 0; true; j++){
                int l = i - j;
                int r = i+1 + j;

                if(l < 0 || r == s.size()){
                    break;
                }

                if(s[l] != s[r]){
                    break;
                }

                int clen = r - l + 1;

                if(clen > plen){
                    st = l;
                    plen = clen;
                }
            }
        }

        return s.substr(st, plen);
    }
};