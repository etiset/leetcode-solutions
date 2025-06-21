class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int curr = 0;
        
        while(curr < intervals.size() && intervals[curr][1] < newInterval[0]){
            res.push_back(intervals[curr]);
            curr++;
        }

        int st = newInterval[0];
        int ed = newInterval[1];

        while(curr < intervals.size() && ed >= intervals[curr][0]){
            st = min(st, intervals[curr][0]);
            ed = max(ed, intervals[curr][1]);
            curr++;
        }

        res.push_back({st, ed});

        while(curr < intervals.size()){
            res.push_back(intervals[curr]);
            curr++;
        }

        return res;
    }
};