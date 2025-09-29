class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cmax = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > cmax){
                return false;
            }

            cmax = max(cmax, i+nums[i]);
        }

        return true;
    }
};