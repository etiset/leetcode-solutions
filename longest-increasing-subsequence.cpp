class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis{0};

        for(int i = 1; i < nums.size(); i++){
            if(nums[lis.back()] < nums[i]){
                lis.push_back(i);
                continue;
            }

            int lo = 0;
            int hi = lis.size()-1;

            while(lo < hi){
                int m = (lo + hi) >> 1;
                
                if(nums[lis[m]] < nums[i]){
                    lo = m + 1;
                }

                else{
                    hi = m;
                }
            }

            lis[lo] = i;
        }

        return lis.size();
    }
};