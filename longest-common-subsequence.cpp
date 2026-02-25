class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size()+1);
        vector<int> curr(text2.size()+1);

        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                curr[j+1] = max(curr[j], prev[j+1]);

                if(text1[i] == text2[j]){
                    curr[j+1] = max(curr[j+1], 1 + prev[j]);
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};