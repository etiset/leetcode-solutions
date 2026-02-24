class Solution {
private:
    const vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int visitIsland(int r, int c, vector<vector<int>>& grid){
        int res = 1;
        grid[r][c] = 0;

        for(auto mov: movs){
            int nr = r + mov.first;
            int nc = c + mov.second;

            if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()){
                continue;
            }

            if(grid[nr][nc] == 1){
                res += visitIsland(nr, nc, grid);
            }
        }

        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    res = max(res, visitIsland(i, j, grid));
                }
            }
        }

        return res;
    }
};