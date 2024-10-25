class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(text2.size()+1);
        vector<int> curr(text2.size()+1);

        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                curr[j] = max(prev[j], curr[j-1]);

                if(text1[i-1] == text2[j-1]){
                    curr[j] = max(curr[j], prev[j-1] + 1);
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};