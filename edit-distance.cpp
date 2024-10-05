class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> res(2, vector<int>(word2.size()+1));

        res[1][0] = 1;
        for(int i = 0; i < word2.size()+1; i++){
            res[0][i] = i;
        }

        for(int i = 0; i < word1.size(); i++){
            for(int j = 0; j < word2.size(); j++){
                int idx1 = i + 1;
                int idx2 = j + 1;

                int &minn = res[1][idx2];
                minn = 1 + min(res[0][idx2], res[1][idx2-1]);
                minn = min(minn, 1 + res[0][idx2-1]);

                if(word1[i] == word2[j]){
                    minn = min(minn, res[0][idx2-1]);
                }
            }

            swap(res[0], res[1]);
            res[1][0] = res[0][0] + 1;
        }

        return res[0].back();
    }
};