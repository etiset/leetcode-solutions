class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int res = 0;
        queue<pair<int, int>> qu;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    grid[i][j] = -2;
                    qu.push(make_pair(i, j));
                }
            }
        }

        while(!qu.empty()){
            auto [u, v] = qu.front();
            qu.pop();

            res = -grid[u][v] - 2;

            for(auto mov: movs){
                int nu = u + mov.first;
                int nv = v + mov.second;

                if(nu < 0 || nu == grid.size() || nv < 0 || nv == grid[0].size()){
                    continue;
                }

                if(grid[nu][nv] == 1){
                    grid[nu][nv] = grid[u][v] - 1;
                    qu.push(make_pair(nu, nv));
                }
            }
        }

        for(int i = 0; i < grid.size(); i++){
            for(int x: grid[i]){
                if(x == 1){
                    return -1;
                }
            }
        }

        return res;
    }
};