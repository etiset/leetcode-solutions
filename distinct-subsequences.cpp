class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> prev(s.size() + 1, 1);
        vector<int> curr(s.size() + 1);

        for(char c: t){
            for(int i = 0; i < s.size(); i++){
                curr[i + 1] = curr[i];

                if(c == s[i] && INT_MAX - curr[i + 1] >= prev[i]){
                    curr[i + 1] += prev[i];
                }
            }

            swap(prev, curr);
            curr[0] = 0;
        }

        return prev.back();
    }
};