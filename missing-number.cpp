class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n+1) / 2;

        int tot = 0;

        for(int num: nums){
            tot += num;
        }

        return expected - tot;
    }
};