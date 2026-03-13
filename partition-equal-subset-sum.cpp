class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);

        if(s & 1){
            return false;
        }

        int target = s >> 1;

        vector<bool> res(target + 1);
        res[0] = true;

        for(int num: nums){
            for(int i = target; i >= num; i--){
                res[i] = res[i] || res[i - num];
            }
        }

        return res.back();
    }
};