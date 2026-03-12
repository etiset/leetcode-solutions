class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        int res = 0;

        for(int offset = 0; offset < 2; offset++){
            int prev3 = 0;
            int prev2 = 0;
            int prev1 = 0;

            for(int i = offset; i < nums.size() - 1 + offset; i++){
                int curr = nums[i] + max(prev3, prev2);

                prev3 = prev2;
                prev2 = prev1;
                prev1 = curr;
            }

            res = max(res, max(prev2, prev1));
        }

        return res;
    }
};