class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        while(true){
            res.push_back(nums);

            int piv = -1;

            for(int i = nums.size() - 2; i >= 0; i--){
                if(nums[i] < nums[i+1]){
                    piv = i;
                    break;
                }
            }

            if(piv == -1){
                break;
            }

            int min_idx = -1;

            for(int i = nums.size() - 1; i > piv; i--){
                if(min_idx == -1){
                    if(nums[i] > nums[piv]){
                        min_idx = i;
                    }

                    continue;
                }

                if(nums[i] > nums[piv] && nums[i] < nums[min_idx]){
                    min_idx = i;
                }
            }

            swap(nums[piv], nums[min_idx]);
            reverse(nums.begin() + (piv+1), nums.end());
        }

        return res;
    }
};