class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r){
                int s = nums[i] + nums[l] + nums[r];

                if(s == 0){
                    res.push_back({nums[i], nums[l], nums[r]});

                    while(l < r && nums[l] == nums[l+1]){
                        l++;
                    }

                    while(l < r && nums[r] == nums[r-1]){
                        r--;
                    }
                }

                if(s <= 0){
                    l++;
                }

                else{
                    r--;
                }
            }
        }

        return res;
    }
};