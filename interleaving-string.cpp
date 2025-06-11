class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        vector<bool> prev(s2.size() + 1);
        vector<bool> curr(s2.size() + 1);
        prev[0] = true;

        for(int i = 0; i < s2.size(); i++){
            prev[i+1] = prev[i] && s2[i] == s3[i];
        }

        for(int i = 1; i <= s1.size(); i++){
            for(int j = 0; j <= s2.size(); j++){
                int k = i+j-1;

                curr[j] = (s3[k] == s1[i-1]) && prev[j];

                if(j > 0 && (s3[k] == s2[j-1]) && curr[j-1]){
                    curr[j] = true;
                }
            }

            swap(prev, curr);
            fill(curr.begin(), curr.end(), false);
        }

        return prev.back();
    }
};