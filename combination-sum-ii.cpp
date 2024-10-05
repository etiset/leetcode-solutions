class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& sols, vector<int>& curr_sol, int rem, int st){
        if(rem <= 0){
            if(rem == 0){
                sols.push_back(curr_sol);
            }

            return;
        }

        for(int i = st; i < candidates.size(); i++){
            int cand = candidates[i];

            if(i > st && cand == candidates[i-1]){
                continue;
            }

            curr_sol.push_back(cand);
            backtrack(candidates, sols, curr_sol, rem - cand, i + 1);
            curr_sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> sols;
        vector<int> curr_sol;

        backtrack(candidates, sols, curr_sol, target, 0);

        return sols;
    }
};