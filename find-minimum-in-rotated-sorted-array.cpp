class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() <= nums.back()){
            return nums.front();
        }

        int lo = 0;
        int hi = nums.size() - 1;

        while(lo < hi){
            int m = (lo + hi) >> 1;

            if(nums[m] <= nums.back()){
                hi = m;
            }

            else{
                lo = m + 1;
            }
        }

        return nums[lo];
    }
};