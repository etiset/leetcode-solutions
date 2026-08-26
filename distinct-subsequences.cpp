class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> prev(s.size() + 1, 1);
        vector<int> curr(s.size() + 1);

        for(int i = 0; i < t.size(); i++){
            for(int j = 1; j <= s.size(); j++){
                curr[j] = curr[j-1];

                if(s[j-1] == t[i] && INT_MAX - curr[j] > prev[j-1]){
                    curr[j] += prev[j-1];
                }
            }

            swap(prev, curr);
            fill(curr.begin(), curr.end(), 0);
        }

        return prev.back();
    }
};