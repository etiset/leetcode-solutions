class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int st = -1;
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i]) == 0){
                mp[s[i]] = -1;
            }

            st = max(st, mp[s[i]]);
            res = max(res, i - st);

            mp[s[i]] = i;
        }

        return res;
    }
};