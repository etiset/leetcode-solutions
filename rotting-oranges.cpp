class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    grid[i][j] = -1;
                    qu.push(make_pair(i, j));
                }
            }
        }

        vector<pair<int, int>> movs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;

        while(!qu.empty()){
            pair<int, int> fr = qu.front();
            qu.pop();

            res = -grid[fr.first][fr.second] - 1;

            for(auto mov: movs){
                int nf = fr.first + mov.first;
                int ns = fr.second + mov.second;

                if(nf < 0 || nf >= grid.size() || ns < 0 || ns >= grid[nf].size()){
                    continue;
                }

                if(grid[nf][ns] == 1){
                    grid[nf][ns] = grid[fr.first][fr.second] - 1;
                    qu.push(make_pair(nf, ns));
                }
            }
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    res = -1;
                }
            }
        }

        return res;
    }
};