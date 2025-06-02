class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int cur_end = 0;
        int max_end = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            max_end = max(max_end, i + nums[i]);

            if(i == cur_end){
                res++;
                cur_end = max_end;
            }
        }

        return res;
    }
};