class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        if(k == 0){
            return;
        }

        int m = n - k;

        reverse(nums.begin(), nums.begin() + m);
        reverse(nums.begin() + m, nums.end());
        reverse(nums.begin(), nums.end());
    }
};