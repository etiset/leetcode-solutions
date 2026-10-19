class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int target = 0;
        int can_reach = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            can_reach = max(can_reach, i + nums[i]);
            
            if(i == target){
                res++;
                target = can_reach;
            }
        }

        return res;
    }
};