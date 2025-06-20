class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        
        for(int i = 0; i < (1 << nums.size()); i++){
            vector<int> x;

            for(int j = 0; j < nums.size(); j++){
                if((i >> j) & 1){
                    x.push_back(nums[j]);
                }
            }

            res.push_back(x);
        }

        return res;
    }
};