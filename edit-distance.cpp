class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> prev(word2.size()+1);
        vector<int> curr(word2.size()+1);

        iota(prev.begin(), prev.end(), 0);

        for(int i = 0; i < word1.size(); i++){
            curr[0] = 1 + prev[0];

            for(int j = 0; j < word2.size(); j++){
                curr[j+1] = 1 + min(curr[j], prev[j+1]);

                int add = (word1[i] != word2[j]);
                curr[j+1] = min(curr[j+1], prev[j] + add);
            }
            
            swap(prev, curr);
        }

        return prev.back();
    }
};