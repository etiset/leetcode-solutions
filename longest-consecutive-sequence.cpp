class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> st(nums.begin(), nums.end());

        for(int num: nums){
            if(st.count(num - 1)){
                continue;
            }

            int curr = num + 1;
            int cand = 1;

            while(st.count(curr)){
                curr++;
                cand++;
            }

            ans = max(ans, cand);
        }

        return ans;
    }
};