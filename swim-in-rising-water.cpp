class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows * cols;

        auto getDistsIndex = [cols](int r, int c){ return r * cols + c; };
        auto getGridIndex = [cols](int idx){ return make_pair(idx/cols, idx%cols); };
        auto isValidCell = [rows, cols](int r, int c){ return r >= 0 && r < rows && c >= 0 && c < cols; };
        vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<int> dists(n, INT_MAX);
        priority_queue<pair<int, int>> pq;

        dists[0] = grid[0][0];
        pq.push(make_pair(-dists[0], 0));

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int w = -it.first;
            int idx = it.second;
            auto [u, v] = getGridIndex(idx);

            if(w > dists[idx]){
                continue;
            }

            for(auto mov: movs){
                int nu = u + mov.first;
                int nv = v + mov.second;
                int nidx = getDistsIndex(nu, nv);

                if(!isValidCell(nu, nv)){
                    continue;
                }

                int cand = max(dists[idx], grid[nu][nv]);
                
                if(cand < dists[nidx]){
                    dists[nidx] = cand;
                    pq.push(make_pair(-cand, nidx));
                }
            }
        }

        return dists.back();
    }
};