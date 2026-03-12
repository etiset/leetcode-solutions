class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> indices = {0};

        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];

            if(nums[indices.back()] < x){
                indices.push_back(i);
                continue;
            }

            int st = 0;
            int ed = indices.size() - 1;

            while(st < ed){
                int m = (st + ed) / 2;

                if(nums[indices[m]] < x){
                    st = m + 1;
                }

                else{
                    ed = m;
                }
            }

            indices[st] = i;
        }

        return indices.size();
    }
};