class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zcnt = 0;

        for(int num: nums){
            if(num == 0){
                zcnt++;
            }

            else{
                prod *= num;
            }
        }

        vector<int> res(nums.size());

        if(zcnt == 0){
            for(int i = 0; i < nums.size(); i++){
                res[i] = prod / nums[i];
            }
        }

        if(zcnt == 1){
            for(int i = 0; i < nums.size(); i++){
                res[i] = (nums[i] == 0) ? prod : 0;
            }
        }

        return res;
    }
};