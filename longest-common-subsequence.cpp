class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size()+1);
        vector<int> curr(text2.size()+1);

        for(int i = 0; i < text1.size(); i++){
            for(int j = 1; j < curr.size(); j++){
                curr[j] = max(curr[j-1], prev[j]);

                if(text1[i] == text2[j-1]){
                    curr[j] = max(curr[j], 1 + prev[j-1]);
                }
            }

            swap(curr, prev);
        }

        return prev.back();
    }
};