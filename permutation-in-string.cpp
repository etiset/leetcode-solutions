class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        int n = s1.size();

        for(int i = 0; i < n; i++){
            cnt1[s1[i] - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            if(i >= n){
                cnt2[s2[i - n] - 'a']--;
            }

            cnt2[s2[i] - 'a']++;

            if(cnt1 == cnt2){
                return true;
            }
        }

        return false;
    }
};