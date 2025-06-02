class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> kv;

        for(int i = 0; i < nums.size(); i++){
            int x = target - nums[i];

            if(kv.count(x)){
                return {i, kv[x]};
            }

            kv[nums[i]] = i;
        }

        return {};
    }
};