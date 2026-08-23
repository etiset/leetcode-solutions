class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        int st = -1;
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i])){
                st = max(st, mp[s[i]]);
            }

            res = max(res, i - st);
            mp[s[i]] = i;
        }

        return res;
    }
};