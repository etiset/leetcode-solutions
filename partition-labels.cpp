class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<pair<int, int>> intervals(26, make_pair(-1, -1));

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';

            if(intervals[idx].first == -1){
                intervals[idx].first = i;
            }

            intervals[idx].second = i;
        }

        sort(intervals.begin(), intervals.end());

        int idx = 0;

        while(intervals[idx].first == -1){
            idx++;
        }

        vector<int> res;

        while(idx < intervals.size()){
            int st = intervals[idx].first;
            int ed = intervals[idx].second;

            while(idx < intervals.size() && intervals[idx].first <= ed){
                ed = max(ed, intervals[idx++].second);
            }

            res.push_back(ed - st + 1);
        }

        return res;
    }
};