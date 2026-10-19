class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr = nums[0];

        for(int i = 1; i < nums.size(); i++){
            curr = max(0, curr) + nums[i];
            res = max(res, curr);
        }

        return res;
    }
};