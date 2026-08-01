class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int fresh = 0;
        queue<tuple<int, int, int>> qu;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                
                if(grid[i][j] == 2){
                    grid[i][j] = 0;
                    qu.push(make_tuple(i, j, 0));
                }
            }
        }
        
        int res = 0;

        while(!qu.empty()){
            auto [r, c, tstamp] = qu.front();
            qu.pop();

            res = tstamp;

            for(auto mov: movs){
                int nr = r + mov.first;
                int nc = c + mov.second;

                if(nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size()){
                    continue;
                }

                if(grid[nr][nc] == 1){
                    fresh--;

                    grid[nr][nc] = 0;
                    qu.push(make_tuple(nr, nc, tstamp + 1));
                }
            }
        }

        if(fresh > 0){
            res = -1;
        }

        return res;
    }
};