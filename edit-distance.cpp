class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> prev(word2.size() + 1);
        vector<int> curr(word2.size() + 1);

        for(int i = 0; i < prev.size(); i++){
            prev[i] = i;
        }

        for(int i = 0; i < word1.size(); i++){
            for(int j = 0; j < prev.size(); j++){
                curr[j] = 1 + prev[j];

                if(j > 0){
                    curr[j] = min(curr[j], 1 + curr[j-1]);
                    curr[j] = min(curr[j], 1 + prev[j-1]);

                    if(word1[i] == word2[j-1]){
                        curr[j] = min(curr[j], prev[j-1]);
                    }
                }
            }

            swap(curr, prev);
        }
        
        return prev.back();
    }
};