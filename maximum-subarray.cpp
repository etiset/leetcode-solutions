class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr_sum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            curr_sum = nums[i] + max(0, curr_sum);
            res = max(res, curr_sum);
        }

        return res;
    }
};