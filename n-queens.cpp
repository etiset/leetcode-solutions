class Solution {
private:
    void findCombinations(int n, vector<vector<string>> &res, vector<int> &cand){
        if(cand.size() == n){
            vector<string> cand_str(n, string(n, '.'));

            for(int i = 0; i < n; i++){
                cand_str[i][cand[i]] = 'Q';
            }

            res.push_back(cand_str);

            return;
        }

        for(int i = 0; i < n; i++){
            bool valid = true;

            for(int j = 0; j < cand.size(); j++){
                if(cand[j] == i){
                    valid = false;
                    break;
                }

                if(abs(i - cand[j]) == cand.size() - j){
                    valid = false;
                    break;
                }
            }

            if(valid){
                cand.push_back(i);
                findCombinations(n, res, cand);
                cand.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cand;

        findCombinations(n, res, cand);

        return res;
    }
};