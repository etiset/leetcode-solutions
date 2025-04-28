class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idxs;

        for(int i = 0; i < nums.size(); i++){
            int val = target - nums[i];

            if(idxs.count(val)){
                return {i, idxs[val]};
            }

            idxs[nums[i]] = i;
        }

        return {};
    }
};