class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = false;

        int curr_max = 0;

        for(int i = 0; i < nums.size() && i <= curr_max; i++){
            curr_max = max(curr_max, i + nums[i]);
        }

        return (curr_max >= nums.size() - 1);
    }
};