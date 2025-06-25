class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo < hi){
            int m = (lo + hi) >> 1;

            if(target > nums[m]){
                lo = m + 1;
            }

            else{
                hi = m;
            }
        }

        return (nums[lo] == target) ? lo : -1;
    }
};