class Solution {
private:
    const vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void visitIsland(int r, int c, vector<vector<char>>& grid){
        for(auto& mov: movs){
            int nr = r + mov.first;
            int nc = c + mov.second;

            if(nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size()){
                continue;
            }

            if(grid[nr][nc] == '1'){
                grid[nr][nc] = '0';
                visitIsland(nr, nc, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    visitIsland(i, j, grid);

                    res++;
                }
            }
        }

        return res;
    }
};