class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        int max_freq = 0;

        for(int num: nums){
            freqs[num]++;
            max_freq = max(max_freq, freqs[num]);
        }

        vector<vector<int>> bkts(max_freq);

        for(auto [num, freq]: freqs){
            bkts[max_freq - freq].push_back(num);
        }

        vector<int> res;

        for(auto bkt: bkts){
            res.insert(res.end(), bkt.begin(), bkt.end());

            if(res.size() >= k){
                break;
            }
        }

        return res;
    }
};