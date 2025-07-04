class Solution {
private:
    int partition(vector<pair<int, int>> &v, int lo, int hi){
        int ran_idx = lo + rand() % (hi - lo + 1);
        swap(v[ran_idx], v[hi]);

        int pivot_val = v[hi].first;
        int leq_idx = lo;

        for(int i = lo; i < hi; i++){
            if(v[i].first <= pivot_val){
                swap(v[leq_idx++], v[i]);
            }
        }

        swap(v[leq_idx], v[hi]);

        return leq_idx;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto squaredDist = [](int x, int y){ return x*x + y*y; };

        vector<pair<int, int>> dists(points.size());
        
        for(int i = 0; i < points.size(); i++){
            dists[i].first = squaredDist(points[i][0], points[i][1]);
            dists[i].second = i;
        }

        int lo = 0;
        int hi = dists.size() - 1;

        while(lo < hi){
            int m = partition(dists, lo, hi);

            if(m == k){
                break;
            }

            else if(m < k){
                lo = m + 1;
            }

            else{
                hi = m - 1;
            }
        }

        vector<vector<int>> res(k);

        for(int i = 0; i < k; i++){
            res[i] = points[dists[i].second];
        }

        return res;
    }
};
