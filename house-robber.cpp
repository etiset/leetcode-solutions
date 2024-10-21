class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        int prev1 = nums[1];
        int prev2 = nums[0];
        int res = max(prev1, prev2);

        for(int i = 2; i < nums.size(); i++){
            res = max(res, nums[i] + prev2);
            prev2 = max(prev2, prev1);
            prev1 = res;
        }

        return res;
    }
};