class Solution {
private:
    int find_index(int x, vector<int> &lis){
        if(lis.empty() || lis.back() < x){
            return lis.size();
        }

        return lower_bound(lis.begin(), lis.end(), x) - lis.begin();
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for(int i = 0; i < nums.size(); i++){
            int idx = find_index(nums[i], lis);

            if(idx == lis.size()){
                lis.push_back(nums[i]);
            }

            else{
                lis[idx] = nums[i];
            }
        }

        return lis.size();
    }
};