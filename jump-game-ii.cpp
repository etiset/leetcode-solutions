class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;

        int curr_reach = 0;
        int max_reach = 0;

        for(int i = 0; i < nums.size()-1; i++){
            max_reach = max(max_reach, i + nums[i]);

            if(i == curr_reach){
                res++;
                curr_reach = max_reach;
            }
        }

        return res;
    }
};