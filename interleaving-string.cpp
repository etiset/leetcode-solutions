class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        vector<bool> prev(s2.size()+1, true);
        vector<bool> curr(s2.size()+1);

        for(int i = 0; i < s2.size(); i++){
            prev[i+1] = prev[i] && (s2[i] == s3[i]);
        }

        for(int i = 0; i < s1.size(); i++){
            curr[0] = prev[0] && (s1[i] == s3[i]);

            for(int j = 0; j < s2.size(); j++){
                int k = i+j+1;

                bool use1 = prev[j+1] && (s1[i] == s3[k]);
                bool use2 = curr[j] && s2[j] == s3[k];

                curr[j+1] = use1 || use2;
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};