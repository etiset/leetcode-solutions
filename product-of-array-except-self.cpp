class Solution {
private:
    int productExceptOne(vector<int>& nums, int index_to_exclude){
        int prod = 1;

        for(int i = 0; i < nums.size(); i++){
            if(i != index_to_exclude){
                prod *= nums[i];
            }
        }

        return prod;
    }

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_cnt = 0;
        int last_zero = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zero_cnt++;
                last_zero = i;
            }
        }

        if(zero_cnt >= 2){
            return vector<int>(nums.size(), 0);
        }

        if(zero_cnt == 1){
            int prod = productExceptOne(nums, last_zero);

            vector<int> res(nums.size(), 0);
            res[last_zero] = prod;

            return res;
        }

        int prod = nums[0] * productExceptOne(nums, 0);
        vector<int> res(nums.size());

        for(int i = 0; i < nums.size(); i++){
            res[i] = prod / nums[i];
        }

        return res;
    }
};