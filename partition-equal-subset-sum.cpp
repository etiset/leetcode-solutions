class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = 0;

        for(int num: nums){
            tot += num;
        }

        if(tot & 1){
            return false;
        }

        int target = tot >> 1;
        vector<bool> prev(target + 1);
        vector<bool> curr(target + 1);
        prev[0] = true;

        for(int num: nums){
            for(int i = 0; i <= target; i++){
                curr[i] = prev[i];

                if(i >= num){
                    curr[i] = curr[i] || prev[i-num];
                }
            }

            swap(prev, curr);
        }

        return prev[target];
    }
};