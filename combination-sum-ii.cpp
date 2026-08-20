class Solution {
private:
    void findCombination(int st, int rem, vector<int>& candidate, vector<vector<int>>& res, vector<int>& nums){
        if(rem < 0){
            return;
        }

        if(st == nums.size()){
            if(rem == 0){
                res.push_back(candidate);
            }

            return;
        }

        int ed = st;

        while(ed < nums.size() && nums[st] == nums[ed]){
            ed++;
        }
        
        for(int i = 0; i <= ed - st; i++){
            findCombination(ed, rem, candidate, res, nums);

            rem -= nums[st];
            candidate.push_back(nums[st]);
        }

        candidate.resize(candidate.size() - (ed - st + 1));
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> candidate;
        vector<vector<int>> res;

        findCombination(0, target, candidate, res, candidates);

        return res;
    }
};