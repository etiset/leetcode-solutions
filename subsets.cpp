class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        for(int msk = 0; msk < (1<<nums.size()); msk++){
            int cmsk = msk;

            for(int i = 0; i < nums.size(); i++){
                if(cmsk&1){
                    curr.push_back(nums[i]);
                }

                cmsk >>= 1;
            }

            res.push_back(curr);
            curr.clear();
        }

        return res;
    }
};