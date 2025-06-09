class Solution {
private:
    void findCombination(const vector<int>&candidates, vector<vector<int>>& res, vector<int>& curr, int idx, int rem){
        if(rem == 0){
            res.push_back(curr);
            return;
        }

        if(idx == candidates.size()){
            return;
        }

        for(int i = 0; true; i++){
            findCombination(candidates, res, curr, idx+1, rem);

            if(rem - candidates[idx] < 0){
                curr.resize(curr.size() - i);
                break;
            }

            curr.push_back(candidates[idx]);
            rem -= candidates[idx];
        }

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        findCombination(candidates, res, curr, 0, target);

        return res;
    }
};