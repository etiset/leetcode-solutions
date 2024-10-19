class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];

        int curr_prod = 1;
        int neg_prefix = 1;

        int ed = 0;

        while(ed < n){
            if(nums[ed] == 0){
                res = max(res, 0);

                curr_prod = 1;
                neg_prefix = 1;

                ed++;

                continue;
            }

            curr_prod *= nums[ed];
            res = max(res, curr_prod);
            
            if(neg_prefix > 0){
                neg_prefix *= nums[ed];
            }

            else{
                res = max(res, curr_prod/neg_prefix);
            }

            ed++;
        }

        return res;
    }
};