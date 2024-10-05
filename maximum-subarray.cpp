class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr = max(0, nums[0]);

        for(int i = 1; i < nums.size(); i++){
            curr += nums[i];
            res = max(res, curr);
            curr = max(0, curr);
        }

        return res;
    }
};