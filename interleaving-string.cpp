class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        int n = s2.size();

        vector<bool> prev(n+1);
        vector<bool> curr(n+1);

        prev[0] = true;

        for(int i = 1; i <= n; i++){
            prev[i] = prev[i-1] && (s2[i-1] == s3[i-1]);
        }

        for(int i = 0; i < s1.size(); i++){
            curr[0] = prev[0] && (s1[i] == s3[i]);

            for(int j = 1; j <= n; j++){
                curr[j] = false;

                if(s1[i] == s3[i+j] && prev[j]){
                    curr[j] = true;
                }

                if(s2[j-1] == s3[i+j] && curr[j-1]){
                    curr[j] = true;
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};