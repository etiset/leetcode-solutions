class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;

        int curr_max = 0;
        int overall_max = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            overall_max = max(overall_max, i + nums[i]);

            if(i == curr_max){
                res++;
                curr_max = overall_max;
            }
        }

        return res;
    }
};