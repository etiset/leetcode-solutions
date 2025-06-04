class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int st = -1;
        unordered_map<char, int> last_occ;

        for(int i = 0; i < s.size(); i++){
            int c = s[i];

            if(last_occ.count(c)){
                st = max(st, last_occ[c]);
            }

            res = max(res, i - st);
            last_occ[c] = i;
        }

        return res;
    }
};