class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_occs;

        int substr_start = -1;
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(last_occs.count(c)){
                substr_start = max(substr_start, last_occs[c]);
            }
            
            res = max(res, i - substr_start);
            last_occs[c] = i;
        }

        return res;
    }
};