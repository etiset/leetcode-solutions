class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        int st = -1;
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(mp.count(c)){
                st = max(st, mp[c]);
            }

            mp[c] = i;
            res = max(res, i - st);
        }

        return res;
    }
};
