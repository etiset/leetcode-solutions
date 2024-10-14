class Solution {
private:
    int calculateMax(vector<int>& nums, int st, int ed){
        int prev1 = 0;
        int prev2 = 0;

        int res = nums[st];

        for(int i = st; i <= ed; i++){
            int cand = nums[i] + prev2;
            res = max(res, cand);

            prev2 = max(prev2, prev1);
            prev1 = cand;
        }

        return max(prev2, prev1);
    }

public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        int op1 = calculateMax(nums, 0, nums.size()-2);
        int op2 = calculateMax(nums, 1, nums.size()-1);

        return max(op1, op2);
    }
};