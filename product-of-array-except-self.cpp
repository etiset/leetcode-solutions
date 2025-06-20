class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zcnt = 0;
        int pr = 1;

        for(int x: nums){
            if(x == 0){
                zcnt++;
            }

            else{
                pr *= x;
            }
        }

        vector<int> res(nums.size());

        if(zcnt == 0){
            for(int i = 0; i < res.size(); i++){
                res[i] = pr / nums[i];
            }
        }

        if(zcnt == 1){
            for(int i = 0; i < res.size(); i++){
                if(nums[i] == 0){
                    res[i] = pr;
                    break;
                }
            }
        }

        return res;
    }
};