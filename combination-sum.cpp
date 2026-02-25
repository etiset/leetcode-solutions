class Solution {
private:
    void generateCombination(int idx, int rem, vector<int>& nums, vector<vector<int>>& res, vector<int>& cand){
        if(rem == 0){
            res.push_back(cand);
            return;
        }

        if(idx == nums.size()){
            return;
        }

        generateCombination(idx+1, rem, nums, res, cand);

        if(nums[idx] <= rem){
            cand.push_back(nums[idx]);
            generateCombination(idx, rem-nums[idx], nums, res, cand);
            cand.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> cand;

        generateCombination(0, target, candidates, res, cand);

        return res;
    }
};