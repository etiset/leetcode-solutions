class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);

        int st = 0;
        int ed = 0;
        int res = 0;

        int curr_max = 0;

        while(ed < s.size()){
            cnt[s[ed] - 'A']++;
            curr_max = max(curr_max, cnt[s[ed] - 'A']);

            if(ed - st + 1 - curr_max > k){
                cnt[s[st] - 'A']--;
                st++;
            }

            res = max(res, ed - st + 1);
            ed++;
        }

        return res;
    }
};