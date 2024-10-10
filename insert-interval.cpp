class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int idx = 0;
        int n = intervals.size();

        while(idx < n && intervals[idx].back() < newInterval.front()){
            res.push_back(intervals[idx++]);
        }

        if(idx == n){
            res.push_back(newInterval);
            return res;
        }

        if(intervals[idx].front() > newInterval.back()){
            res.push_back(newInterval);
        }
        
        else{
            int st = min(intervals[idx].front(), newInterval.front());
            int ed = max(intervals[idx].back(), newInterval.back());

            idx++;
            while(idx < n && intervals[idx].front() <= ed){
                ed = max(ed, intervals[idx++].back());
            }

            res.push_back({st, ed});
        }

        while(idx < n){
            res.push_back(intervals[idx++]);
        }

        return res;
    }
};