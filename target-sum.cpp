class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);

        if((target + s) % 2 || abs(target) > s){
            return 0;
        }

        int p = (s + target) / 2;
        vector<int> combs(p + 1);
        combs[0] = 1;

        for(int num: nums){
            for(int i = p; i >= num; i--){
                combs[i] += combs[i - num];
            }
        }

        return combs.back();
    }
};