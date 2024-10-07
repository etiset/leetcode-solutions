class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        if(s1 == s3 || s2 == s3){
            return true;
        }

        vector<bool> prev(s3.size() + 1, false);
        vector<bool> curr(s3.size() + 1, false);

        prev[0] = true;
        for(int i = 0; i < s2.size(); i++){
            prev[i+1] = prev[i] && (s2[i] == s3[i]);
        }

        for(int i = 0; i < s1.size(); i++){
            curr[0] = prev[0] && (s1[i] == s3[i]);

            for(int j = 0; j < s3.size(); j++){
                if(j >= s2.size()){
                    curr[j+1] = false;
                    continue;
                }

                int k = i + j + 1;

                bool op1 = prev[j+1] && (s1[i] == s3[k]);
                bool op2 = curr[j] && (s2[j] == s3[k]);

                curr[j+1] = op1 || op2;

                if(k + 1 == s3.size() && curr[j+1]){
                    return true;
                }
            }

            swap(prev, curr);
        }

        return false;
    }
};