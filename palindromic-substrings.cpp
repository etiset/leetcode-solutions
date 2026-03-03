class Solution {
private:
    int calculatePalindromes(int u, int v, string& s){
        int res = 0;

        while(u >= 0 && v < s.size() && s[u] == s[v]){
            u--;
            v++;
            res++;
        }

        return res;
    }

public:
    int countSubstrings(string s) {
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            res += calculatePalindromes(i, i, s);
            res += calculatePalindromes(i, i+1, s);
        }

        return res;
    }
};