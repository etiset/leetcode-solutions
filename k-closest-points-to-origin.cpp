class Solution {
private:
    int partition(vector<pair<int, int>>& dists, int st, int ed){
        int ridx = st + (rand() % (ed - st + 1));

        int pivot = dists[ridx].first;
        swap(dists[ridx], dists[ed]);

        int leq_idx = st;

        for(int i = st; i < ed; i++){
            if(dists[i].first < pivot){
                swap(dists[i], dists[leq_idx++]);
            }
        }

        swap(dists[leq_idx], dists[ed]);

        return leq_idx;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> dists(points.size());

        for(int i = 0; i < points.size(); i++){
            int dx = points[i][0];
            int dy = points[i][1];

            dists[i].first = dx * dx + dy * dy;
            dists[i].second = i;
        }

        int st = 0;
        int ed = points.size() - 1;

        while(st < ed){
            int m = partition(dists, st, ed);

            if(m == k - 1){
                break;
            }

            if(k < m){
                ed = m - 1;
            }

            else{
                st = m + 1;
            }
        }

        vector<vector<int>> res;

        for(int i = 0; i < k; i++){
            res.push_back(points[dists[i].second]);
        }

        return res;
    }
};