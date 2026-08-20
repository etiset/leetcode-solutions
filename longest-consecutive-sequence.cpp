class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int res = 0;

        for(int x: st){
            if(st.count(x-1)){
                continue;
            }

            int val = x;
            int cand = 0;

            while(st.count(val++)){
                cand++;
            }

            res = max(res, cand);
        }

        return res;
    }
};