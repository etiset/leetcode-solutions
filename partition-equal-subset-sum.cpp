class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);

        if(tot & 1){
            return false;
        }

        int target = tot >> 1;
        vector<bool> prev(target+1);
        vector<bool> curr(target+1);
        prev[0] = true;

        for(int x : nums){
            for(int i = target; i > -1; i--){
                curr[i] = prev[i];

                if(i >= x){
                    curr[i] = curr[i] || prev[i-x];
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};