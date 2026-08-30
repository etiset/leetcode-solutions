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

            if(nums[m] < target){
                st = m + 1;
            }

            else{
                ed = m - 1;
            }
        }

        return -1;
    }
};