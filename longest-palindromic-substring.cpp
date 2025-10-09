class Solution {
public:
    string longestPalindrome(string s) {
        int pst = 0;
        int plen = -1;

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; i-j >= 0 && i+j < s.size(); j++){
                if(s[i-j] != s[i+j]){
                    break;
                }

                if(plen < 2*j+1){
                    pst = i-j;
                    plen = 2*j+1;
                }
            }

            for(int j = 1; i-j >= 0 && i+j-1 < s.size(); j++){
                if(s[i-j] != s[i+j-1]){
                    break;
                }

                if(plen < 2*j){
                    pst = i-j;
                    plen = 2*j;
                }
            }
        }

        return s.substr(pst, plen);
    }
};