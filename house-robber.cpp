class Solution {
public:
    int rob(vector<int>& nums) {
        int prev3 = 0;
        int prev2 = 0;
        int prev1 = 0;

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i] + max(prev3, prev2);

            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return max(prev2, prev1);
    }
};