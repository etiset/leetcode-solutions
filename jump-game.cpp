class Solution {
public:
    bool canJump(vector<int>& nums) {
        int upto = 0;
        int target = nums.size() - 1;

        for(int i = 0; i <= upto; i++){
            if(upto >= target){
                return true;
            }

            upto = max(upto, i + nums[i]);
        }

        return false;
    }
};