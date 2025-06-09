class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int, int, int>> qu;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    qu.push(make_tuple(i, j, 0));
                }
            }
        }

        int res = 0;

        while(!qu.empty()){
            auto [u, v, t] = qu.front();
            qu.pop();

            res = max(res, t);

            for(auto mov: movs){
                int r = u + mov.first;
                int s = v + mov.second;

                if(r < 0 || r == m || s < 0 || s == n){
                    continue;
                }

                if(grid[r][s] == 1){
                    grid[r][s] = 2;
                    qu.push(make_tuple(r, s, t + 1));
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return res;
    }
};