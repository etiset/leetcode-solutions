class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for(auto& interval: intervals){
            if(res.size() == 0 || res.back()[1] < interval[0]){
                res.push_back(interval);
                continue;
            }
            
            res.back()[1] = max(res.back()[1], interval[1]);
        }

        return res;
    }
};