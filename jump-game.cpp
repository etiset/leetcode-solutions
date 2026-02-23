class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;

        for(int i = 0; i < nums.size(); i++){
            if(max_reach < i){
                return false;
            }

            int reach = i + nums[i];
            max_reach = max(max_reach, reach);
        }

        return true;
    }
};