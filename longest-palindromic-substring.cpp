class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0;
        int res_st;

        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;

            while(l > -1 && r < s.size()){
                if(s[l] != s[r]){
                    break;
                }

                int curr_len = r - l + 1;

                if(max_len < curr_len){
                    max_len = curr_len;
                    res_st = l;
                }

                l--;
                r++;
            }
        }

        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i + 1;

            while(l > -1 && r < s.size()){
                if(s[l] != s[r]){
                    break;
                }

                int curr_len = r - l + 1;

                if(max_len < curr_len){
                    max_len = curr_len;
                    res_st = l;
                }

                l--;
                r++;
            }
        }

        return s.substr(res_st, max_len);
    }
};