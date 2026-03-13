class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        };

        sort(intervals.begin(), intervals.end(), cmp);

        int res = 0;
        int ed = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < ed){
                res++;
            }

            else{
                ed = intervals[i][1];
            }
        }

        return res;
    }
};