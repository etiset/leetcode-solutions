class Solution {
private:
    void findSolution(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int idx){
        res.push_back(curr);

        for(int i = idx; i < nums.size(); i++){
            curr.push_back(nums[i]);
            findSolution(nums, res, curr, i+1);
            curr.pop_back();

            while(i+1 < nums.size() && nums[i] == nums[i+1]){
                i++;
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        vector<vector<int>> res;

        findSolution(nums, res, curr, 0);

        return res;
    }
};