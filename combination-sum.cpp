class Solution {
private:
    void findCombination(int st, int rem, vector<int>& candidate, vector<vector<int>>& res, vector<int>& nums){
        if(rem == 0){
            res.push_back(candidate);
            return;
        }

        if(st == nums.size()){
            return;
        }

        findCombination(st + 1, rem, candidate, res, nums);

        if(rem >= nums[st]){
            candidate.push_back(nums[st]);
            findCombination(st, rem - nums[st], candidate, res, nums);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> candidate;
        vector<vector<int>> res;

        findCombination(0, target, candidate, res, candidates);

        return res;
    }
};