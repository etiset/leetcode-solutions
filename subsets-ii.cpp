class Solution {
private:
    void findNextSubset(vector<int>& nums, vector<vector<int>> &sols, vector<int> &curr_sol, int st){
        sols.push_back(curr_sol);

        for(int i = st; i < nums.size(); i++){
            curr_sol.push_back(nums[i]);
            findNextSubset(nums, sols, curr_sol, i+1);
            curr_sol.pop_back();

            while(i+1 < nums.size() && nums[i] == nums[i+1]){
                i++;
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> sols;
        vector<int> curr_sol;

        findNextSubset(nums, sols, curr_sol, 0);

        return sols;
    }
};