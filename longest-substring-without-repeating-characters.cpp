class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int leftmost = -1;
        unordered_map<char, int> last_occ;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(last_occ.count(c)){
                leftmost = max(leftmost, last_occ[c]);
            }

            res = max(res, i - leftmost);
            last_occ[c] = i;
        }

        return res;
    }
};