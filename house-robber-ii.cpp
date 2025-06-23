class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 2){
            return *max_element(nums.begin(), nums.end());
        }

        int res = 0;
        vector<pair<int, int>> opts = {{0, nums.size()-2}, {1, nums.size()-1}};

        for(auto [st, ed]: opts){
            int prev2 = nums[st];
            int prev1 = nums[st+1];

            for(int i = st+2; i <= ed; i++){
                int curr = prev2 + nums[i];

                prev2 = max(prev2, prev1);
                prev1 = curr;
            }

            res = max(res, max(prev2, prev1));
        }

        return res;
    }
};