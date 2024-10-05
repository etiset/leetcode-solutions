class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }

        int jumps = 1;
        int st = 0;
        int ed = nums[0];
        int target = nums.size() - 1;

        while(ed < target){
            int ned = ed;
            
            for(int i = st; i <= ed; i++){
                ned = max(ned, i + nums[i]);
            }

            jumps++;
            st = ed + 1;
            ed = ned;
        }

        return jumps;
    }
};