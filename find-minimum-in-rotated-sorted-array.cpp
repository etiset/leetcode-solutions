class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() <= nums.back()){
            return nums.front();
        }

        int st = 1;
        int ed = nums.size() - 1;

        while(st < ed){
            int m = (st + ed) / 2;

            if(nums[m] <= nums.back()){
                ed = m;
            }
            
            else{
                st = m + 1;
            }
        }

        return nums[st];
    }
};