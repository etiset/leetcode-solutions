class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        int max_freq = 0;

        for(int x: nums){
            freqs[x]++;
            max_freq = max(max_freq, freqs[x]);
        }

        vector<vector<int>> bkts(max_freq);

        for(auto it: freqs){
            bkts[max_freq - it.second].push_back(it.first);
        }

        vector<int> res;

        for(auto it: bkts){
            res.insert(res.end(), it.begin(), it.end());

            if(res.size() >= k){
                break;
            }
        }

        return res;
    }
};