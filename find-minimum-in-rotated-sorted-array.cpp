class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo < hi){
            int m = (lo + hi) / 2;

            if(nums[m] > nums[hi]){
                lo = m + 1;
            }

            else{
                hi = m;
            }
        }

        return nums[lo];
    }
};