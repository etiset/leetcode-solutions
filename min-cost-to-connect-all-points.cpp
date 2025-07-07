class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto calculateDist = [](const vector<int> &a, const vector<int> &b){ return abs(a[0] - b[0]) + abs(a[1] - b[1]); };

        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n);

        pq.push({0, 0});

        int edges_used = 0;
        int res = 0;

        while(!pq.empty() && edges_used < n){
            auto [w, u] = pq.top();
            pq.pop();

            if(visited[u]){
                continue;
            }

            visited[u] = true;
            edges_used++;
            res += w;

            for(int v = 0; v < n; v++){
                if(v != u && !visited[v]){
                    pq.push({calculateDist(points[u], points[v]), v});
                }
            }
        }

        return res;
    }
};