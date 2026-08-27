class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int max_freq = 0;
        unordered_map<int, int> freqs;

        for(int num: nums){
            max_freq = max(max_freq, ++freqs[num]);
        }

        vector<vector<int>> bkts(max_freq + 1);

        for(auto [num, freq]: freqs){
            bkts[freq].push_back(num);
        }

        vector<int> res;

        for(int i = max_freq; i >= 0; i--){
            for(int num: bkts[i]){
                res.push_back(num);
                k--;

                if(k == 0){
                    return res;
                }
            }
        }

        return res;
    }
};