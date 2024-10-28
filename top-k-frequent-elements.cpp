class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int max_freq = 0;

        for(int num: nums){
            cnt[num]++;
            max_freq = max(max_freq, cnt[num]);
        }

        vector<vector<int>> bkts(max_freq + 1, vector<int>());

        for(auto& it: cnt){
            bkts[it.second].push_back(it.first);
        }

        vector<int> res;

        for(int i = max_freq; i > 0; i--){
            if(k == 0){
                break;
            }

            for(int x: bkts[i]){
                res.push_back(x);
                k--;
            }
        }

        return res;
    }
};