class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;

        unordered_set<int> st(nums.begin(), nums.end());

        for(int x: st){
            if(st.count(x - 1)){
                continue;
            }

            for(int i = 0; st.count(x + i); i++){
                res = max(res, i + 1);
            }
        }

        return res;
    }
};