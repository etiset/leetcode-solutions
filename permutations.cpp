class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1){
            return {{1}};
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int cnt = 0;

        while(true){
            res.push_back(nums);

            int lidx = nums.size() - 2;

            while(lidx >= 0 && nums[lidx] > nums[lidx+1]){
                lidx--;
            }

            if(lidx == -1){
                break;
            }

            int ridx = nums.size() - 1;

            while(nums[lidx] > nums[ridx]){
                ridx--;
            }

            swap(nums[lidx], nums[ridx]);
            reverse(nums.begin() + (lidx+1), nums.end());
        }

        return res;
    }
};