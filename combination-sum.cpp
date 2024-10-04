class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> combs(target+1);
        combs[0].push_back({});

        for(int cand: candidates){
            for(int i = cand; i <= target; i++){
                int prev = i - cand;

                for(auto comb: combs[prev]){
                    vector<int> ncomb = comb;
                    ncomb.push_back(cand);

                    combs[i].push_back(ncomb);
                }
            }
        }

        return combs.back();
    }
};