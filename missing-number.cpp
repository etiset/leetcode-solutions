class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size() * (nums.size() + 1) >> 1;

        for(int num: nums){
            res -= num;
        }

        return res;
    }
};