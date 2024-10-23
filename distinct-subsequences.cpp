class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> prev(s.size()+1, 1);
        vector<long long> curr(s.size()+1);

        for(char c: t){
            for(int i = 0; i <= s.size(); i++){
                if(i == 0){
                    curr[i] = 0;
                    continue;
                }

                curr[i] = curr[i-1];

                if(c == s[i-1]){
                    if(INT_MAX - curr[i] < prev[i-1]){
                        break;
                    }

                    curr[i] += prev[i-1];
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};