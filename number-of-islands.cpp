class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> movs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int res = 0;

        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> qu;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '0'){
                    continue;
                }

                res++;
                grid[i][j] = 0;
                qu.push(make_pair(i, j));

                while(!qu.empty()){
                    auto fr = qu.front();
                    qu.pop();

                    for(auto mov: movs){
                        int nr = fr.first + mov.first;
                        int nc = fr.second + mov.second;

                        if(nr < 0 || nr == r || nc < 0 || nc == c){
                            continue;
                        }

                        if(grid[nr][nc] == '0'){
                            continue;
                        }

                        grid[nr][nc] = '0';
                        qu.push(make_pair(nr, nc));
                    }
                }
            }
        }

        return res;
    }
};