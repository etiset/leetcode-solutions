class Solution {
private:
    bool isInvalidMask(int msk, vector<int>& nums){
        for(int st = 0; st < nums.size();){
            int ed = st;
            bool found_gap = false;

            while(ed < nums.size() && nums[ed] == nums[st]){
                if(((msk >> ed) & 1) == 0){
                    found_gap = true;
                }

                else if(found_gap){
                    return true;
                }

                ed++;
            }

            st = ed;
        }

        return false;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int upto = 1 << nums.size();
        vector<int> cand;

        for(int msk = 0; msk < upto; msk++){
            int cand_msk = msk;

            if(isInvalidMask(cand_msk, nums)){
                continue;
            }

            for(int j = 0; j < nums.size(); j++){
                if((cand_msk >> j) & 1){
                    cand.push_back(nums[j]);
                }
            }

            res.push_back(cand);
            cand.clear();
        }

        return res;
    }
};