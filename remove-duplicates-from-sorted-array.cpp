class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;

        for(int it = 0; it < nums.size();){
            nums[res] = nums[it];

            int jt = it + 1;

            while(jt < nums.size() && nums[it] == nums[jt]){
                jt++;
            }

            res++;
            it = jt;
        }

        return res;
    }
};