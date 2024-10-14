class Solution {
private:
    int countPalindromes(string& s, int i, int j){
        int res = 0;

        while(i >= 0 && j < s.size()){
            if(s[i] != s[j]){
                break;
            }

            res++;
            i--;
            j++;
        }

        return res;
    }

public:
    int countSubstrings(string s) {
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            res += countPalindromes(s, i, i);

            if(i > 0){
                res += countPalindromes(s, i-1, i);
            }
        }

        return res;
    }
};