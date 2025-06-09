class Solution {
private:
    void findSolutions(const vector<int>& candidates, vector<vector<int>>& res, vector<int>& curr, int idx, int rem){
        if(rem == 0){
            res.push_back(curr);
            return;
        }

        if(idx == candidates.size()){
            return;
        }
        
        int nidx = idx + 1;

        while(nidx < candidates.size() && candidates[nidx] == candidates[idx]){
            nidx++;
        }

        int currlen = curr.size();
        for(int i = 0; i <= nidx - idx; i++){
            findSolutions(candidates, res, curr, nidx, rem);

            if(rem - candidates[idx] < 0){
                break;
            }

            curr.push_back(candidates[idx]);
            rem -= candidates[idx];
        }

        curr.resize(currlen);
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        findSolutions(candidates, res, curr, 0, target);

        return res;
    }
};