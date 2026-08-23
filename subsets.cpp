class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        for(int msk = 0; msk < (1 << (nums.size())); msk++){
            vector<int> cand;
            int cand_msk = msk;

            for(int i = 0; i < nums.size(); i++){
                if((cand_msk >> i) & 1){
                    cand.push_back(nums[i]);
                }
            }

            res.push_back(cand);
        }

        return res;
    }
};