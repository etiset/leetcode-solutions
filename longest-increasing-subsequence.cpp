class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for(int i = 0; i < nums.size(); i++){
            if(lis.empty() || nums[lis.back()] < nums[i]){
                lis.push_back(i);
                continue;
            }

            int lo = 0;
            int hi = lis.size() - 1;

            while(lo < hi){
                int m = (lo + hi) >> 1;

                if(nums[i] <= nums[lis[m]]){
                    hi = m;
                }

                else{
                    lo = m + 1;
                }
            }

            lis[lo] = i;
        }

        return lis.size();
    }
};