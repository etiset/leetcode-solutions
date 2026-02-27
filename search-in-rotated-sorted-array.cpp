class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int ed = nums.size() - 1;

        while(st <= ed){
            int m = (st + ed) / 2;

            if(nums[m] == target){
                return m;
            }

            if(nums[m] < nums[ed]){
                if(nums[m] < target && target <= nums[ed]){
                    st = m + 1;
                }

                else{
                    ed = m - 1;
                }
            }

            else{
                if(nums[m] < target || nums[ed] >= target){
                    st = m + 1;
                }

                else{
                    ed = m - 1;
                }
            }
        }

        return -1;
    }
};