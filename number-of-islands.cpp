class Solution {
private:
    void traverseIsland(vector<vector<char>>& grid, int u, int v) {
        vector<vector<int>> movs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> qu;
        qu.push(make_pair(u, v));
        grid[u][v] = -1;

        while(!qu.empty()){
            auto [u, v] = qu.front();
            qu.pop();

            for(auto mov: movs){
                int nu = u + mov[0];
                int nv = v + mov[1];

                if(0 > nu || nu >= grid.size() || 0 > nv || nv >= grid[0].size()){
                    continue;
                }

                if(grid[nu][nv] != '1'){
                    continue;
                }

                qu.push(make_pair(nu, nv));
                grid[nu][nv] = '2';
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    traverseIsland(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};
