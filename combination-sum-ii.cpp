class Solution {
private:
    void generateCombinations(int st, int rem, vector<int>& nums, vector<vector<int>>& res, vector<int>& candidate){
        if(rem == 0){
            res.push_back(candidate);
            return;
        }

        if(st == nums.size()){
            return;
        }

        int ed = st;

        while(ed < nums.size() && nums[ed] == nums[st]){
            ed++;
        }

        for(int i = st; i <= ed; i++){
            generateCombinations(ed, rem, nums, res, candidate);

            if(rem < nums[st]){
                ed = i - 1;
                break;
            }

            rem -= nums[st];
            candidate.push_back(nums[st]);
        }

        candidate.resize(candidate.size() - (ed - st + 1));
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> candidate;

        generateCombinations(0, target, candidates, res, candidate);

        return res;
    }
};