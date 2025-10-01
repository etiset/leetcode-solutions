class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> prev(word2.size()+1);
        vector<int> curr(word2.size()+1);

        for(int i = 0; i < prev.size(); i++){
            prev[i] = i;
        }

        for(int i = 0; i < word1.size(); i++){
            for(int j = 0; j < curr.size(); j++){
                curr[j] = prev[j] + 1;

                if(j > 0){
                    curr[j] = min(curr[j], curr[j-1] + 1);

                    int add = (word1[i] == word2[j-1]) ? 0 : 1;
                    curr[j] = min(curr[j], prev[j-1] + add);
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};