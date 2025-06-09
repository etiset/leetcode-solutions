class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        unordered_set<int> st(nums.begin(), nums.end());
        int res = 1;

        for(int x: st){
            if(st.count(x - 1)){
                continue;
            }

            int cand = 1;

            while(st.count(x + cand)){
                cand++;
                res = max(res, cand);
            }
        }

        return res;
    }
};