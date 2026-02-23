class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int u = 0;
        int v = 0;

        do {
            u = nums[u];
            v = nums[nums[v]];
        } while(u != v);

        u = 0;

        while(u != v){
            u = nums[u];
            v = nums[v];
        }

        return u;
    }
};