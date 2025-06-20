class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; true; j++){
                if(i-j < 0 || i+j == s.size() || s[i-j] != s[i+j]){
                    break;
                }

                res++;
            }

            for(int j = 0; true; j++){
                if(i-j < 0 || i+1+j == s.size() || s[i-j] != s[i+1+j]){
                    break;
                }

                res++;
            }
        }

        return res;
    }
};