class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};

        for(int num: nums){
            int sz = res.size();

            for(int i = 0; i < sz; i++){
                auto st = res[i];
                st.push_back(num);
                res.push_back(st);
            }
        }

        return res;
    }
};