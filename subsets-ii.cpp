class Solution {
private:
    void generateSubsets(int idx, vector<int>& nums, vector<vector<int>>& res, vector<int> &cand){
        res.push_back(cand);

        for(int i = idx; i < nums.size();){
            cand.push_back(nums[i]);
            generateSubsets(i+1, nums, res, cand);
            cand.pop_back();

            i++;

            while(i < nums.size() && nums[i] == nums[i-1]){
                i++;
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> cand;

        generateSubsets(0, nums, res, cand);

        return res;
    }
};