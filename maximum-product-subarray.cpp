class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        for(int l = 0; l < nums.size(); l++){
            if(nums[l] == 0){
                res = max(res, 0);
                continue;
            }

            int curr = nums[l];
            res = max(res, curr);

            int r = l;

            while(r+1 < nums.size() && nums[r+1] != 0){
                curr *= nums[++r];
                res = max(res, curr);
            }

            while(l <= r){
                res = max(res, curr);
                curr /= nums[l++];
            }

            if(r+1 < nums.size()){
                res = max(res, 0);
            }

            l = r+1;
        }

        return res;
    }
};