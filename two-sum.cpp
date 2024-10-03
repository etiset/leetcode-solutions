class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2ind;
        
        for(int i = 0; i < nums.size(); i++){
            int missing_num = target - nums[i];

            if(num2ind.count(missing_num) != 0){
                return vector<int> {i, num2ind[missing_num]};
            }

            num2ind[nums[i]] = i;
        }

        return {};
    }
};