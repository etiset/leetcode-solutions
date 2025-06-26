class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo <= hi){
            int m = (lo + hi) >> 1;

            if(nums[m] == target){
                return m;
            }

            if(nums[m] > nums[hi]){
                if(nums[lo] <= target && target < nums[m]){
                    hi = m - 1;
                }

                else{
                    lo = m + 1;
                }
            }

            else{
                if(nums[m] < target && target <= nums[hi]){
                    lo = m + 1;
                }

                else{
                    hi = m - 1;
                }
            }
        }

        return -1;
    }
};