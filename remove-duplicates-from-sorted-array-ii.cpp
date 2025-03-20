class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;

        for(int it = 0; it < nums.size();){
            int jt = it + 1;

            while(jt < nums.size() && nums[it] == nums[jt]){
                jt++;
            }

            int len = min(jt - it, 2);
            nums[res++] = nums[it];

            if(len == 2){
                nums[res++] = nums[it];
            }

            it = jt;
        }

        return res;
    }
};