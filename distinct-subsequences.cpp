class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> prev(s.size()+1, 1);
        vector<int> curr(s.size()+1);

        for(int i = 0; i < t.size(); i++){
            curr[0] = 0;

            for(int j = 1; j < curr.size(); j++){
                curr[j] = curr[j-1];

                if(t[i] == s[j-1] && curr[j] <= INT_MAX - prev[j-1]){
                    curr[j] += prev[j-1];
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};