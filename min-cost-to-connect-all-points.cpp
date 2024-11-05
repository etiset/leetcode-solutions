class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);

        pq.push({0, 0});

        int res = 0;
        int visited_count = 0;

        while(!pq.empty() && visited_count < n){
            auto [cost, u] = pq.top();
            pq.pop();

            if(visited[u]){
                continue;
            }

            visited[u] = true;
            res += cost;
            visited_count++;

            for(int v = 0; v < n; v++){
                if(!visited[v]){
                    int w0 = abs(points[u][0] - points[v][0]);
                    int w1 = abs(points[u][1] - points[v][1]);
                    int w = w0 + w1;

                    pq.push({w, v});
                }
            }
        }

        return res;
    }
};