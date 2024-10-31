class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, int>> query_index_pairs(queries.size());

        for(int i = 0; i < queries.size(); i++){
            query_index_pairs[i].first = queries[i];
            query_index_pairs[i].second = i;
        }

        sort(query_index_pairs.begin(), query_index_pairs.end());
        sort(intervals.begin(), intervals.end());

        vector<int> res(queries.size(), -1);

        int idx = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto& [query, res_idx]: query_index_pairs){
            while(idx < intervals.size() && intervals[idx][0] <= query){
                int len = intervals[idx][1] - intervals[idx][0] + 1;
                pq.push(make_pair(len, intervals[idx][1]));

                idx++;
            }

            while(!pq.empty() && pq.top().second < query){
                pq.pop();
            }

            if(!pq.empty()){
                res[res_idx] = pq.top().first;
            }
        }

        return res;
    }
};