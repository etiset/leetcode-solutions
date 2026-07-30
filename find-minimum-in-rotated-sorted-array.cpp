class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() < nums.back()){
            return nums.front();
        }

        int st = 0;
        int ed = nums.size() - 1;

        while(st < ed){
            int m = (st + ed) / 2;

            if(nums[ed] < nums[m]){
                st = m + 1;
            }

            else{
                ed = m;
            }
        }

        return nums[st];
    }
};