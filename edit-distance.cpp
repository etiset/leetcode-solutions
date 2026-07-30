class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> prev(word2.size() + 1);
        vector<int> curr(word2.size() + 1);

        iota(prev.begin(), prev.end(), 0);

        for(int i = 1; i <= word1.size(); i++){
            curr[0] = i;

            for(int j = 1; j <= word2.size(); j++){
                curr[j] = 1 + min(curr[j-1], prev[j]);

                int val = (word1[i-1] != word2[j-1]);
                curr[j] = min(curr[j], val + prev[j-1]);
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};