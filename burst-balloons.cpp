class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> res(nums.size(), vector<int>(nums.size()));

        int n = nums.size();

        for(int roffset = 0; roffset < n; roffset++){
            for(int lidx = 0, ridx = roffset; ridx < n; lidx++, ridx++){
                for(int m = lidx; m <= ridx; m++){
                    int lsum = (m == lidx) ? 0 : res[lidx][m-1];
                    int rsum = (m == ridx) ? 0 : res[m+1][ridx];

                    int lfact = (lidx == 0) ? 1 : nums[lidx-1];
                    int rfact = (ridx == n-1) ? 1 : nums[ridx+1];

                    int cand = lsum + lfact * nums[m] * rfact + rsum;
                    res[lidx][ridx] = max(cand, res[lidx][ridx]);
                }
            }
        }

        return res[0][nums.size() - 1];
    }
};