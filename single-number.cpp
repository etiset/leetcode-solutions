class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int bits = 0;

        for(int i = 0; i < nums.size(); i++){
            bits ^= nums[i];
        }

        return bits;
    }
};