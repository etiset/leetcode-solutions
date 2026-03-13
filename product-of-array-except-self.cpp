class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        int zcnt = count(nums.begin(), nums.end(), 0);

        if(zcnt >= 2){
            return res;
        }

        int prod = 1;

        for(int num: nums){
            if(num != 0){
                prod *= num;
            }
        }

        if(zcnt == 0){
            for(int i = 0; i < res.size(); i++){
                res[i] = prod / nums[i];
            }
        }

        else{
            for(int i = 0; i < res.size(); i++){
                if(nums[i] == 0){
                    res[i] = prod;
                }
            }
        }

        return res;
    }
};