class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> occs(26);

        int st = 0;
        int mocc = 0;
        int res = 0;

        for(int ed = 0; ed < s.size(); ed++){
            occs[s[ed] - 'A']++;
            mocc = max(mocc, occs[s[ed] - 'A']);

            if(ed - st + 1 - mocc > k){
                occs[s[st] - 'A']--;
                st++;
            }

            res = max(res, ed - st + 1);
        }

        return res;
    }
};