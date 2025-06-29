class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if((total + target) & 1 != 0 || abs(target) > total){
            return 0;
        }

        target = (target + total) >> 1;
        vector<int> res(target+1);
        res[0] = 1;

        for(int num: nums){
            for(int curr = target; curr >= num; curr--){
                res[curr] += res[curr - num];
            }
        }

        return res.back();
    }
};